/********************************************************************************
** Form generated from reading UI file 'newwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWWIDGET_H
#define UI_NEWWIDGET_H

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

class Ui_newWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditIp;
    QLabel *label_2;
    QLineEdit *lineEditPort;
    QTextEdit *textEdit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *buttonSend;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonClose;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *newWidget)
    {
        if (newWidget->objectName().isEmpty())
            newWidget->setObjectName(QString::fromUtf8("newWidget"));
        newWidget->resize(497, 370);
        gridLayout = new QGridLayout(newWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(newWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        lineEditIp = new QLineEdit(newWidget);
        lineEditIp->setObjectName(QString::fromUtf8("lineEditIp"));

        gridLayout->addWidget(lineEditIp, 0, 2, 1, 2);

        label_2 = new QLabel(newWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        lineEditPort = new QLineEdit(newWidget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

        gridLayout->addWidget(lineEditPort, 1, 2, 1, 2);

        textEdit = new QTextEdit(newWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 2, 0, 1, 5);

        horizontalSpacer_2 = new QSpacerItem(99, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 0, 1, 1);

        buttonSend = new QPushButton(newWidget);
        buttonSend->setObjectName(QString::fromUtf8("buttonSend"));

        gridLayout->addWidget(buttonSend, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 2, 1, 1);

        buttonClose = new QPushButton(newWidget);
        buttonClose->setObjectName(QString::fromUtf8("buttonClose"));

        gridLayout->addWidget(buttonClose, 3, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(99, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 4, 1, 1);


        retranslateUi(newWidget);

        QMetaObject::connectSlotsByName(newWidget);
    } // setupUi

    void retranslateUi(QWidget *newWidget)
    {
        newWidget->setWindowTitle(QCoreApplication::translate("newWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("newWidget", "\345\257\271\346\226\271\347\232\204IP", nullptr));
        lineEditIp->setText(QCoreApplication::translate("newWidget", "127.0.0.1", nullptr));
        label_2->setText(QCoreApplication::translate("newWidget", "\345\257\271\346\226\271\347\232\204\347\253\257\345\217\243", nullptr));
        buttonSend->setText(QCoreApplication::translate("newWidget", "Send", nullptr));
        buttonClose->setText(QCoreApplication::translate("newWidget", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newWidget: public Ui_newWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWWIDGET_H
