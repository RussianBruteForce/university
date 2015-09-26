#include "mt.h"
#include "ui_mt.h"

MT::MT(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::MT)
{
	ui->setupUi(this);
	model = new MTModel(this);
	ui->tableView->setModel(model);
	ui->tableView->resizeColumnsToContents();

	ui->rangeEdit->setValidator(new QIntValidator(2,1000,this));
	connect(ui->rangeEdit, &QLineEdit::returnPressed,
		this, &MT::changeRange);

	void (QSpinBox::*VC)(int) = &QSpinBox::valueChanged;
	connect(ui->precisionSpinBox, VC,
		model, &MTModel::setPrecision);
	ui->label_2->setVisible(false);
	ui->precisionSpinBox->setVisible(false);

	QStringList bases;
	bases += QString::number(2);
	bases += QString::number(8);
	bases += QString::number(10);
	bases += QString::number(16);
	bases += "e";
	ui->comboBox->insertItems(0, bases);
	ui->comboBox->setCurrentIndex(2);
	void (QComboBox::*IC)(int) = &QComboBox::currentIndexChanged;
	connect(ui->comboBox, IC,
		this, &MT::changeBase);
}

MT::~MT()
{
	delete ui;
}

void MT::changeBase(int b)
{
	bool precisionVisibility = false;
	switch (b) {
	case 0:
		model->setBase(2);
		break;
	case 1:
		model->setBase(8);
		break;
	case 2:
		model->setBase(10);
		break;
	case 3:
		model->setBase(16);
		break;
	case 4:
		model->setBase(MY_E);
		precisionVisibility = true;
		break;
	default:
		break;
	}
	ui->label_2->setVisible(precisionVisibility);
	ui->precisionSpinBox->setVisible(precisionVisibility);
	ui->tableView->resizeColumnsToContents();
}

void MT::changeRange()
{
	model->setRange(ui->rangeEdit->text().toInt());
	ui->rangeEdit->clear();
	ui->tableView->resizeColumnsToContents();
}
