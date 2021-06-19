/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

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

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonClose;
    QLabel *label;
    QTextEdit *textEdit;
    QPushButton *buttonSend;
    QLabel *label_2;
    QLineEdit *lineEditPort;
    QLineEdit *lineEditIp;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(486, 390);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_3 = new QSpacerItem(118, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(185, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 3, 1, 1);

        buttonClose = new QPushButton(Widget);
        buttonClose->setObjectName(QString::fromUtf8("buttonClose"));

        gridLayout->addWidget(buttonClose, 3, 4, 1, 1);

        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 2, 0, 1, 6);

        buttonSend = new QPushButton(Widget);
        buttonSend->setObjectName(QString::fromUtf8("buttonSend"));

        gridLayout->addWidget(buttonSend, 3, 1, 1, 2);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditPort = new QLineEdit(Widget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

        gridLayout->addWidget(lineEditPort, 1, 2, 1, 3);

        lineEditIp = new QLineEdit(Widget);
        lineEditIp->setObjectName(QString::fromUtf8("lineEditIp"));

        gridLayout->addWidget(lineEditIp, 0, 2, 1, 3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        buttonClose->setText(QCoreApplication::translate("Widget", "Close", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\345\257\271\346\226\271\347\232\204IP", nullptr));
        buttonSend->setText(QCoreApplication::translate("Widget", "Send", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\345\257\271\346\226\271\347\232\204\347\253\257\345\217\243", nullptr));
        lineEditIp->setText(QCoreApplication::translate("Widget", "127.0.0.1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
