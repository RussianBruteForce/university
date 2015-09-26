/********************************************************************************
** Form generated from reading UI file 'mt.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MT_H
#define UI_MT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MT
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QSpinBox *precisionSpinBox;
    QSpacerItem *horizontalSpacer;
    QLineEdit *rangeEdit;

    void setupUi(QWidget *MT)
    {
        if (MT->objectName().isEmpty())
            MT->setObjectName(QStringLiteral("MT"));
        MT->resize(464, 405);
        verticalLayout = new QVBoxLayout(MT);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableView = new QTableView(MT);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->horizontalHeader()->setDefaultSectionSize(40);
        tableView->verticalHeader()->setDefaultSectionSize(30);

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(MT);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(MT);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        label_2 = new QLabel(MT);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        precisionSpinBox = new QSpinBox(MT);
        precisionSpinBox->setObjectName(QStringLiteral("precisionSpinBox"));
        precisionSpinBox->setMaximum(16);
        precisionSpinBox->setValue(4);

        horizontalLayout->addWidget(precisionSpinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        rangeEdit = new QLineEdit(MT);
        rangeEdit->setObjectName(QStringLiteral("rangeEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rangeEdit->sizePolicy().hasHeightForWidth());
        rangeEdit->setSizePolicy(sizePolicy);
        rangeEdit->setMaximumSize(QSize(105, 16777215));

        horizontalLayout->addWidget(rangeEdit);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MT);

        QMetaObject::connectSlotsByName(MT);
    } // setupUi

    void retranslateUi(QWidget *MT)
    {
        MT->setWindowTitle(QApplication::translate("MT", "MT", 0));
        label->setText(QApplication::translate("MT", "Base:", 0));
        label_2->setText(QApplication::translate("MT", "Precision:", 0));
        rangeEdit->setPlaceholderText(QApplication::translate("MT", "Another range", 0));
    } // retranslateUi

};

namespace Ui {
    class MT: public Ui_MT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MT_H
