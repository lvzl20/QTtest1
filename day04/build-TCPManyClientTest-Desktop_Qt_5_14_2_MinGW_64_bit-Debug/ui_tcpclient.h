/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpClient
{
public:
    QTextEdit *textEditShowMsg;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *textEditSendMsg;
    QPushButton *buttonSend;
    QLineEdit *lineEditIp;
    QLineEdit *lineEditUserName;
    QLineEdit *lineEditPort;
    QPushButton *buttonJoin;

    void setupUi(QWidget *TcpClient)
    {
        if (TcpClient->objectName().isEmpty())
            TcpClient->setObjectName(QString::fromUtf8("TcpClient"));
        TcpClient->resize(530, 380);
        textEditShowMsg = new QTextEdit(TcpClient);
        textEditShowMsg->setObjectName(QString::fromUtf8("textEditShowMsg"));
        textEditShowMsg->setGeometry(QRect(9, 9, 512, 201));
        textEditShowMsg->setReadOnly(true);
        label = new QLabel(TcpClient);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(214, 322, 48, 16));
        label_2 = new QLabel(TcpClient);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(9, 322, 60, 16));
        label_3 = new QLabel(TcpClient);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(9, 293, 36, 16));
        textEditSendMsg = new QTextEdit(TcpClient);
        textEditSendMsg->setObjectName(QString::fromUtf8("textEditSendMsg"));
        textEditSendMsg->setGeometry(QRect(9, 236, 303, 51));
        buttonSend = new QPushButton(TcpClient);
        buttonSend->setObjectName(QString::fromUtf8("buttonSend"));
        buttonSend->setGeometry(QRect(320, 250, 75, 23));
        lineEditIp = new QLineEdit(TcpClient);
        lineEditIp->setObjectName(QString::fromUtf8("lineEditIp"));
        lineEditIp->setGeometry(QRect(75, 322, 133, 20));
        lineEditUserName = new QLineEdit(TcpClient);
        lineEditUserName->setObjectName(QString::fromUtf8("lineEditUserName"));
        lineEditUserName->setGeometry(QRect(75, 294, 133, 20));
        lineEditPort = new QLineEdit(TcpClient);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));
        lineEditPort->setGeometry(QRect(318, 322, 133, 20));
        buttonJoin = new QPushButton(TcpClient);
        buttonJoin->setObjectName(QString::fromUtf8("buttonJoin"));
        buttonJoin->setGeometry(QRect(208, 348, 75, 23));

        retranslateUi(TcpClient);

        QMetaObject::connectSlotsByName(TcpClient);
    } // setupUi

    void retranslateUi(QWidget *TcpClient)
    {
        TcpClient->setWindowTitle(QCoreApplication::translate("TcpClient", "Form", nullptr));
        label->setText(QCoreApplication::translate("TcpClient", "\347\253\257\345\217\243\345\234\260\345\235\200", nullptr));
        label_2->setText(QCoreApplication::translate("TcpClient", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", nullptr));
        label_3->setText(QCoreApplication::translate("TcpClient", "\347\224\250\346\210\267\345\220\215", nullptr));
        buttonSend->setText(QCoreApplication::translate("TcpClient", "\345\217\221\351\200\201", nullptr));
        lineEditIp->setText(QCoreApplication::translate("TcpClient", "127.0.0.1", nullptr));
        lineEditPort->setText(QCoreApplication::translate("TcpClient", "8888", nullptr));
        buttonJoin->setText(QCoreApplication::translate("TcpClient", "\345\212\240\345\205\245\350\201\212\345\244\251\345\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpClient: public Ui_TcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
