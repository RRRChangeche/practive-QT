/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QComboBox *cmbType;
    QLabel *label;
    QLineEdit *leValue;
    QLabel *label_2;
    QLineEdit *leMultiplier;
    QLabel *label_3;
    QLineEdit *leResult;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCalculate;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(361, 229);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_4 = new QLabel(Dialog);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        cmbType = new QComboBox(Dialog);
        cmbType->setObjectName("cmbType");

        gridLayout->addWidget(cmbType, 0, 1, 1, 1);

        label = new QLabel(Dialog);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 0, 1, 1);

        leValue = new QLineEdit(Dialog);
        leValue->setObjectName("leValue");

        gridLayout->addWidget(leValue, 1, 1, 1, 1);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        leMultiplier = new QLineEdit(Dialog);
        leMultiplier->setObjectName("leMultiplier");

        gridLayout->addWidget(leMultiplier, 2, 1, 1, 1);

        label_3 = new QLabel(Dialog);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        leResult = new QLineEdit(Dialog);
        leResult->setObjectName("leResult");

        gridLayout->addWidget(leResult, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCalculate = new QPushButton(Dialog);
        btnCalculate->setObjectName("btnCalculate");

        horizontalLayout->addWidget(btnCalculate);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "Type", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Value", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Multiplier", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "Result", nullptr));
        btnCalculate->setText(QCoreApplication::translate("Dialog", "Calculate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
