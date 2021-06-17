/********************************************************************************
** Form generated from reading UI file 'clientwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIDGET_H
#define UI_CLIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientWidget
{
public:
    QLabel *label;
    QLineEdit *lineEditIp;
    QLabel *label_2;
    QLineEdit *lineEditPort;
    QPushButton *buttonConnect;

    void setupUi(QWidget *clientWidget)
    {
        if (clientWidget->objectName().isEmpty())
            clientWidget->setObjectName(QString::fromUtf8("clientWidget"));
        clientWidget->resize(566, 380);
        label = new QLabel(clientWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 40, 71, 16));
        lineEditIp = new QLineEdit(clientWidget);
        lineEditIp->setObjectName(QString::fromUtf8("lineEditIp"));
        lineEditIp->setGeometry(QRect(140, 40, 161, 20));
        label_2 = new QLabel(clientWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 80, 61, 16));
        lineEditPort = new QLineEdit(clientWidget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));
        lineEditPort->setGeometry(QRect(140, 80, 161, 20));
        buttonConnect = new QPushButton(clientWidget);
        buttonConnect->setObjectName(QString::fromUtf8("buttonConnect"));
        buttonConnect->setGeometry(QRect(370, 60, 75, 23));

        retranslateUi(clientWidget);

        QMetaObject::connectSlotsByName(clientWidget);
    } // setupUi

    void retranslateUi(QWidget *clientWidget)
    {
        clientWidget->setWindowTitle(QCoreApplication::translate("clientWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("clientWidget", "\346\234\215\345\212\241\345\231\250IP", nullptr));
        lineEditIp->setText(QCoreApplication::translate("clientWidget", "127.0.0.1", nullptr));
        label_2->setText(QCoreApplication::translate("clientWidget", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", nullptr));
        lineEditPort->setText(QCoreApplication::translate("clientWidget", "8888", nullptr));
        buttonConnect->setText(QCoreApplication::translate("clientWidget", "connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clientWidget: public Ui_clientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H
