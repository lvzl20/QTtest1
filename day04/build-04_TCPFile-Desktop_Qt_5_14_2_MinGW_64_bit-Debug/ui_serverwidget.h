/********************************************************************************
** Form generated from reading UI file 'serverwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWIDGET_H
#define UI_SERVERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serverWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEdit;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *buttonSelect;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *buttonSend;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *serverWidget)
    {
        if (serverWidget->objectName().isEmpty())
            serverWidget->setObjectName(QString::fromUtf8("serverWidget"));
        serverWidget->resize(509, 362);
        gridLayout = new QGridLayout(serverWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(89, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        label = new QLabel(serverWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 2, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(89, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        textEdit = new QTextEdit(serverWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 1, 0, 1, 6);

        horizontalSpacer_4 = new QSpacerItem(89, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 0, 1, 1);

        buttonSelect = new QPushButton(serverWidget);
        buttonSelect->setObjectName(QString::fromUtf8("buttonSelect"));

        gridLayout->addWidget(buttonSelect, 2, 1, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(90, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 3, 1, 1);

        buttonSend = new QPushButton(serverWidget);
        buttonSend->setObjectName(QString::fromUtf8("buttonSend"));

        gridLayout->addWidget(buttonSend, 2, 4, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(89, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 2, 5, 1, 1);


        retranslateUi(serverWidget);

        QMetaObject::connectSlotsByName(serverWidget);
    } // setupUi

    void retranslateUi(QWidget *serverWidget)
    {
        serverWidget->setWindowTitle(QCoreApplication::translate("serverWidget", "serverWidget", nullptr));
        label->setText(QCoreApplication::translate("serverWidget", "\346\234\215\345\212\241\345\231\250", nullptr));
        buttonSelect->setText(QCoreApplication::translate("serverWidget", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        buttonSend->setText(QCoreApplication::translate("serverWidget", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serverWidget: public Ui_serverWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWIDGET_H
