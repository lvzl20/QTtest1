/********************************************************************************
** Form generated from reading UI file 'logui.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGUI_H
#define UI_LOGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogUi
{
public:
    QPushButton *buttonHide;
    QPushButton *buttonClose;
    QLabel *labelIcon;
    QLabel *labelTitle;
    QPushButton *buttonLog;
    QPushButton *buttonSignUp;
    QSplitter *splitter_2;
    QLineEdit *lineEditAccount;
    QLineEdit *lineEditPassword;
    QSplitter *splitter;
    QCheckBox *checkBoxLog;
    QCheckBox *checkBoxRem;
    QPushButton *pushButton;

    void setupUi(QWidget *LogUi)
    {
        if (LogUi->objectName().isEmpty())
            LogUi->setObjectName(QString::fromUtf8("LogUi"));
        LogUi->resize(430, 330);
        buttonHide = new QPushButton(LogUi);
        buttonHide->setObjectName(QString::fromUtf8("buttonHide"));
        buttonHide->setGeometry(QRect(350, 10, 30, 25));
        buttonClose = new QPushButton(LogUi);
        buttonClose->setObjectName(QString::fromUtf8("buttonClose"));
        buttonClose->setGeometry(QRect(390, 10, 30, 25));
        labelIcon = new QLabel(LogUi);
        labelIcon->setObjectName(QString::fromUtf8("labelIcon"));
        labelIcon->setGeometry(QRect(10, 10, 40, 40));
        labelTitle = new QLabel(LogUi);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setGeometry(QRect(50, 10, 40, 40));
        buttonLog = new QPushButton(LogUi);
        buttonLog->setObjectName(QString::fromUtf8("buttonLog"));
        buttonLog->setGeometry(QRect(110, 270, 191, 31));
        buttonSignUp = new QPushButton(LogUi);
        buttonSignUp->setObjectName(QString::fromUtf8("buttonSignUp"));
        buttonSignUp->setGeometry(QRect(10, 300, 75, 23));
        buttonSignUp->setFlat(true);
        splitter_2 = new QSplitter(LogUi);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setGeometry(QRect(100, 140, 221, 81));
        splitter_2->setOrientation(Qt::Vertical);
        lineEditAccount = new QLineEdit(splitter_2);
        lineEditAccount->setObjectName(QString::fromUtf8("lineEditAccount"));
        splitter_2->addWidget(lineEditAccount);
        lineEditPassword = new QLineEdit(splitter_2);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        splitter_2->addWidget(lineEditPassword);
        splitter = new QSplitter(LogUi);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(100, 230, 217, 23));
        splitter->setOrientation(Qt::Horizontal);
        checkBoxLog = new QCheckBox(splitter);
        checkBoxLog->setObjectName(QString::fromUtf8("checkBoxLog"));
        splitter->addWidget(checkBoxLog);
        checkBoxRem = new QCheckBox(splitter);
        checkBoxRem->setObjectName(QString::fromUtf8("checkBoxRem"));
        splitter->addWidget(checkBoxRem);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFlat(true);
        splitter->addWidget(pushButton);

        retranslateUi(LogUi);

        QMetaObject::connectSlotsByName(LogUi);
    } // setupUi

    void retranslateUi(QWidget *LogUi)
    {
        LogUi->setWindowTitle(QCoreApplication::translate("LogUi", "LogUi", nullptr));
        buttonHide->setText(QCoreApplication::translate("LogUi", "1", nullptr));
        buttonClose->setText(QCoreApplication::translate("LogUi", "2", nullptr));
        labelIcon->setText(QCoreApplication::translate("LogUi", "Icon", nullptr));
        labelTitle->setText(QCoreApplication::translate("LogUi", "Title", nullptr));
        buttonLog->setText(QCoreApplication::translate("LogUi", "\347\231\273\345\275\225", nullptr));
        buttonSignUp->setText(QCoreApplication::translate("LogUi", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        checkBoxLog->setText(QCoreApplication::translate("LogUi", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        checkBoxRem->setText(QCoreApplication::translate("LogUi", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        pushButton->setText(QCoreApplication::translate("LogUi", "\346\211\276\345\233\236\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogUi: public Ui_LogUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGUI_H
