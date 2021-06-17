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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditIp;
    QTextEdit *textEditRead;
    QTextEdit *textEditWrite;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *buttonSend;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonDisconnect;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEditPort;
    QPushButton *buttonConnect;

    void setupUi(QWidget *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName(QString::fromUtf8("ClientWidget"));
        ClientWidget->resize(411, 339);
        gridLayout = new QGridLayout(ClientWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ClientWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        label_2 = new QLabel(ClientWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        lineEditIp = new QLineEdit(ClientWidget);
        lineEditIp->setObjectName(QString::fromUtf8("lineEditIp"));

        gridLayout->addWidget(lineEditIp, 1, 2, 1, 3);

        textEditRead = new QTextEdit(ClientWidget);
        textEditRead->setObjectName(QString::fromUtf8("textEditRead"));
        textEditRead->setReadOnly(true);

        gridLayout->addWidget(textEditRead, 2, 0, 1, 6);

        textEditWrite = new QTextEdit(ClientWidget);
        textEditWrite->setObjectName(QString::fromUtf8("textEditWrite"));

        gridLayout->addWidget(textEditWrite, 3, 0, 1, 6);

        horizontalSpacer_2 = new QSpacerItem(69, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 0, 1, 1);

        buttonSend = new QPushButton(ClientWidget);
        buttonSend->setObjectName(QString::fromUtf8("buttonSend"));

        gridLayout->addWidget(buttonSend, 4, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(69, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 3, 1, 1);

        buttonDisconnect = new QPushButton(ClientWidget);
        buttonDisconnect->setObjectName(QString::fromUtf8("buttonDisconnect"));

        gridLayout->addWidget(buttonDisconnect, 4, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(72, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 4, 5, 1, 1);

        lineEditPort = new QLineEdit(ClientWidget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

        gridLayout->addWidget(lineEditPort, 0, 2, 1, 3);

        buttonConnect = new QPushButton(ClientWidget);
        buttonConnect->setObjectName(QString::fromUtf8("buttonConnect"));

        gridLayout->addWidget(buttonConnect, 0, 5, 2, 1);


        retranslateUi(ClientWidget);

        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientWidget)
    {
        ClientWidget->setWindowTitle(QCoreApplication::translate("ClientWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243:", nullptr));
        label_2->setText(QCoreApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250IP\357\274\232", nullptr));
        lineEditIp->setText(QCoreApplication::translate("ClientWidget", "127.0.0.1", nullptr));
        buttonSend->setText(QCoreApplication::translate("ClientWidget", "Send", nullptr));
        buttonDisconnect->setText(QCoreApplication::translate("ClientWidget", "Disconnect", nullptr));
        lineEditPort->setText(QCoreApplication::translate("ClientWidget", "8888", nullptr));
        buttonConnect->setText(QCoreApplication::translate("ClientWidget", "connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H
