#ifndef MTMODEL_H
#define MTMODEL_H

#include <QAbstractTableModel>
#include <QString>
#include <cmath>
#include "doublylinkedlist.h"

#define MY_E 88

class MTModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	explicit MTModel(QObject *parent = 0) :
	       QAbstractTableModel(parent),
	       base(10),
	       precision(4)
	{
		setRange(10);
	}
	int columnCount(const QModelIndex & parent = QModelIndex()) const;
	int rowCount(const QModelIndex & = QModelIndex()) const;
	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
signals:

public slots:
	void setBase(int b);
	void setRange(int r);
	void setPrecision(int p);

private:
	int base;
	DoublyLinkedList<u_int8_t> list;
	int precision;

	QString mul(const u_int8_t &a,const u_int8_t &b) const;
	double toE(u_int8_t x) const;
};


#endif // MTMODEL_H
