#include "mtmodel.h"

int MTModel::columnCount(const QModelIndex&) const
{
	return list.size();
}

int MTModel::rowCount(const QModelIndex&) const
{
	return list.size();
}

QVariant MTModel::data(const QModelIndex& index, int role) const
{
	if (!index.isValid())
		return QVariant();
	if (index.row() >= static_cast<int>(list.size()))
		return QVariant();
	if (role == Qt::DisplayRole){
		return mul(
			list.at(list.size() -1 - index.row()),
			list.at(list.size() -1 - index.column()));
	}
	return QVariant();
}

QVariant MTModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if(role != Qt::DisplayRole)
		return QVariant();
	if ((orientation == Qt::Horizontal || orientation == Qt::Vertical)) {
		if (base != MY_E)
			return QString::number(list.at(list.size() -1 - section), base);
		else
			return QString::number(toE(list.size() -1 - list.at(section)),'G',precision);
	}
	return QVariant();
}

void MTModel::setBase(int b)
{
	base = b;
	if (
			b == 2 ||
			b == 8 ||
			b == 10 ||
			b == 16
			) {
		setRange(b);
	} else if (b == MY_E){
		setRange(3);
	} else {
		return;
	}
}

void MTModel::setRange(int r)
{
	list.clear();
	for(u_int8_t i = 1; i <= static_cast<u_int8_t>(r); i++)
		list.add(i);
	emit dataChanged(index(0,0),index(rowCount(),columnCount()));
	emit headerDataChanged(Qt::Horizontal,0,15);
	emit headerDataChanged(Qt::Vertical,0,15);
}

void MTModel::setPrecision(int p)
{
	precision = p;
	emit dataChanged(index(0,0),index(rowCount(),columnCount()));
	emit headerDataChanged(Qt::Horizontal,0,15);
	emit headerDataChanged(Qt::Vertical,0,15);
}

QString MTModel::mul(const u_int8_t& a, const u_int8_t& b) const
{
	if (base != MY_E)
		return QString::number(a*b,base);
	else {
		return  QString::number(toE(a*b),'f',precision);
	}
	return QString("NO DATA");
}

double MTModel::toE(u_int8_t x) const
{
	return pow(x, M_E);
}
