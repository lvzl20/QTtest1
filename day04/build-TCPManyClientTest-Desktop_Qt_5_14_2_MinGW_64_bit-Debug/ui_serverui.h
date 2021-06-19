/********************************************************************************
** Form generated from reading UI file 'serverui.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERUI_H
#define UI_SERVERUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serverUi
{
public:
    QTextEdit *textEdit;

    void setupUi(QWidget *serverUi)
    {
        if (serverUi->objectName().isEmpty())
            serverUi->setObjectName(QString::fromUtf8("serverUi"));
        serverUi->resize(542, 370);
        textEdit = new QTextEdit(serverUi);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 20, 511, 291));
        textEdit->setReadOnly(true);

        retranslateUi(serverUi);

        QMetaObject::connectSlotsByName(serverUi);
    } // setupUi

    void retranslateUi(QWidget *serverUi)
    {
        serverUi->setWindowTitle(QCoreApplication::translate("serverUi", "serverUi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serverUi: public Ui_serverUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERUI_H
