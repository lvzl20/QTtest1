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
    QLabel *label_3;
    QLabel *label_2;
    QTextEdit *textEditSendMsg;
    QPushButton *buttonSelectFile;
    QTextEdit *textEditSelectFile;
    QLineEdit *lineEditUserName;
    QPushButton *buttonSend;
    QLineEdit *lineEditIp;
    QPushButton *buttonJoin;
    QTextEdit *textEditShowMsg;
    QLabel *label;
    QLineEdit *lineEditPort;

    void setupUi(QWidget *TcpClient)
    {
        if (TcpClient->objectName().isEmpty())
            TcpClient->setObjectName(QString::fromUtf8("TcpClient"));
        TcpClient->resize(527, 392);
        label_3 = new QLabel(TcpClient);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1, 291, 36, 16));
        label_2 = new QLabel(TcpClient);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1, 320, 60, 16));
        textEditSendMsg = new QTextEdit(TcpClient);
        textEditSendMsg->setObjectName(QString::fromUtf8("textEditSendMsg"));
        textEditSendMsg->setGeometry(QRect(2, 208, 303, 31));
        buttonSelectFile = new QPushButton(TcpClient);
        buttonSelectFile->setObjectName(QString::fromUtf8("buttonSelectFile"));
        buttonSelectFile->setGeometry(QRect(312, 258, 75, 23));
        textEditSelectFile = new QTextEdit(TcpClient);
        textEditSelectFile->setObjectName(QString::fromUtf8("textEditSelectFile"));
        textEditSelectFile->setGeometry(QRect(2, 248, 301, 31));
        textEditSelectFile->setReadOnly(true);
        lineEditUserName = new QLineEdit(TcpClient);
        lineEditUserName->setObjectName(QString::fromUtf8("lineEditUserName"));
        lineEditUserName->setGeometry(QRect(67, 292, 133, 20));
        buttonSend = new QPushButton(TcpClient);
        buttonSend->setObjectName(QString::fromUtf8("buttonSend"));
        buttonSend->setGeometry(QRect(312, 218, 75, 23));
        lineEditIp = new QLineEdit(TcpClient);
        lineEditIp->setObjectName(QString::fromUtf8("lineEditIp"));
        lineEditIp->setGeometry(QRect(67, 320, 133, 20));
        buttonJoin = new QPushButton(TcpClient);
        buttonJoin->setObjectName(QString::fromUtf8("buttonJoin"));
        buttonJoin->setGeometry(QRect(200, 346, 75, 23));
        textEditShowMsg = new QTextEdit(TcpClient);
        textEditShowMsg->setObjectName(QString::fromUtf8("textEditShowMsg"));
        textEditShowMsg->setGeometry(QRect(1, 7, 512, 201));
        textEditShowMsg->setReadOnly(true);
        label = new QLabel(TcpClient);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(206, 320, 48, 16));
        lineEditPort = new QLineEdit(TcpClient);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));
        lineEditPort->setGeometry(QRect(310, 320, 133, 20));

        retranslateUi(TcpClient);

        QMetaObject::connectSlotsByName(TcpClient);
    } // setupUi

    void retranslateUi(QWidget *TcpClient)
    {
        TcpClient->setWindowTitle(QCoreApplication::translate("TcpClient", "TcpClient", nullptr));
        label_3->setText(QCoreApplication::translate("TcpClient", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("TcpClient", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", nullptr));
        buttonSelectFile->setText(QCoreApplication::translate("TcpClient", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        buttonSend->setText(QCoreApplication::translate("TcpClient", "\345\217\221\351\200\201", nullptr));
        lineEditIp->setText(QCoreApplication::translate("TcpClient", "127.0.0.1", nullptr));
        buttonJoin->setText(QCoreApplication::translate("TcpClient", "\345\212\240\345\205\245\350\201\212\345\244\251\345\256\244", nullptr));
        label->setText(QCoreApplication::translate("TcpClient", "\347\253\257\345\217\243\345\234\260\345\235\200", nullptr));
        lineEditPort->setText(QCoreApplication::translate("TcpClient", "8888", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpClient: public Ui_TcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
