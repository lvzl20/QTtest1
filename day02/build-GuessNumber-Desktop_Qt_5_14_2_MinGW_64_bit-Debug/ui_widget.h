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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *pageSet;
    QLabel *label_title;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_start;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_end;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *label_guess;
    QComboBox *comboBox;
    QWidget *pageGame;
    QPushButton *pushButton_num0;
    QPushButton *pushButton_num1;
    QPushButton *pushButton_num2;
    QPushButton *pushButton_num3;
    QPushButton *pushButton_num4;
    QPushButton *pushButton_num5;
    QPushButton *pushButton_num6;
    QPushButton *pushButton_num7;
    QPushButton *pushButton_num8;
    QPushButton *pushButton_num9;
    QPushButton *pushButton_numComplete;
    QPushButton *pushButton_numDelete;
    QProgressBar *progressBar;
    QLabel *label_process;
    QLabel *label_inputNum;
    QPushButton *pushButton_numTip;
    QLineEdit *lineEdit_inputNum;
    QPushButton *pushButton_back;
    QWidget *pageWin;
    QLabel *label_win;
    QLabel *label;
    QWidget *pageEnd;
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QLabel *label_end;
    QLabel *label_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->setEnabled(true);
        Widget->resize(524, 365);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setEnabled(true);
        stackedWidget->setGeometry(QRect(20, 30, 481, 320));
        pageSet = new QWidget();
        pageSet->setObjectName(QString::fromUtf8("pageSet"));
        label_title = new QLabel(pageSet);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(130, 30, 201, 51));
        QFont font;
        font.setPointSize(30);
        label_title->setFont(font);
        layoutWidget = new QWidget(pageSet);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 230, 321, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_start = new QPushButton(layoutWidget);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));

        horizontalLayout->addWidget(pushButton_start);

        horizontalSpacer = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_end = new QPushButton(layoutWidget);
        pushButton_end->setObjectName(QString::fromUtf8("pushButton_end"));

        horizontalLayout->addWidget(pushButton_end);

        layoutWidget1 = new QWidget(pageSet);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(110, 130, 231, 40));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_guess = new QLabel(layoutWidget1);
        label_guess->setObjectName(QString::fromUtf8("label_guess"));

        verticalLayout->addWidget(label_guess);

        comboBox = new QComboBox(layoutWidget1);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        stackedWidget->addWidget(pageSet);
        pageGame = new QWidget();
        pageGame->setObjectName(QString::fromUtf8("pageGame"));
        pushButton_num0 = new QPushButton(pageGame);
        pushButton_num0->setObjectName(QString::fromUtf8("pushButton_num0"));
        pushButton_num0->setGeometry(QRect(1, 249, 75, 30));
        pushButton_num0->setStyleSheet(QString::fromUtf8(""));
        pushButton_num1 = new QPushButton(pageGame);
        pushButton_num1->setObjectName(QString::fromUtf8("pushButton_num1"));
        pushButton_num1->setGeometry(QRect(82, 249, 75, 30));
        pushButton_num2 = new QPushButton(pageGame);
        pushButton_num2->setObjectName(QString::fromUtf8("pushButton_num2"));
        pushButton_num2->setGeometry(QRect(163, 249, 75, 30));
        pushButton_num3 = new QPushButton(pageGame);
        pushButton_num3->setObjectName(QString::fromUtf8("pushButton_num3"));
        pushButton_num3->setGeometry(QRect(244, 249, 75, 30));
        pushButton_num4 = new QPushButton(pageGame);
        pushButton_num4->setObjectName(QString::fromUtf8("pushButton_num4"));
        pushButton_num4->setGeometry(QRect(325, 249, 75, 30));
        pushButton_num5 = new QPushButton(pageGame);
        pushButton_num5->setObjectName(QString::fromUtf8("pushButton_num5"));
        pushButton_num5->setGeometry(QRect(1, 283, 75, 30));
        pushButton_num6 = new QPushButton(pageGame);
        pushButton_num6->setObjectName(QString::fromUtf8("pushButton_num6"));
        pushButton_num6->setGeometry(QRect(82, 283, 75, 30));
        pushButton_num7 = new QPushButton(pageGame);
        pushButton_num7->setObjectName(QString::fromUtf8("pushButton_num7"));
        pushButton_num7->setGeometry(QRect(163, 283, 75, 30));
        pushButton_num8 = new QPushButton(pageGame);
        pushButton_num8->setObjectName(QString::fromUtf8("pushButton_num8"));
        pushButton_num8->setGeometry(QRect(244, 283, 75, 30));
        pushButton_num9 = new QPushButton(pageGame);
        pushButton_num9->setObjectName(QString::fromUtf8("pushButton_num9"));
        pushButton_num9->setGeometry(QRect(325, 283, 75, 30));
        pushButton_numComplete = new QPushButton(pageGame);
        pushButton_numComplete->setObjectName(QString::fromUtf8("pushButton_numComplete"));
        pushButton_numComplete->setGeometry(QRect(406, 249, 75, 30));
        QFont font1;
        font1.setPointSize(11);
        pushButton_numComplete->setFont(font1);
        pushButton_numDelete = new QPushButton(pageGame);
        pushButton_numDelete->setObjectName(QString::fromUtf8("pushButton_numDelete"));
        pushButton_numDelete->setGeometry(QRect(406, 283, 75, 30));
        QFont font2;
        font2.setPointSize(15);
        pushButton_numDelete->setFont(font2);
        progressBar = new QProgressBar(pageGame);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(70, 40, 400, 23));
        progressBar->setValue(0);
        label_process = new QLabel(pageGame);
        label_process->setObjectName(QString::fromUtf8("label_process"));
        label_process->setGeometry(QRect(10, 40, 50, 23));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        label_process->setFont(font3);
        label_inputNum = new QLabel(pageGame);
        label_inputNum->setObjectName(QString::fromUtf8("label_inputNum"));
        label_inputNum->setGeometry(QRect(10, 100, 111, 21));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font4.setPointSize(10);
        label_inputNum->setFont(font4);
        pushButton_numTip = new QPushButton(pageGame);
        pushButton_numTip->setObjectName(QString::fromUtf8("pushButton_numTip"));
        pushButton_numTip->setGeometry(QRect(200, 220, 75, 30));
        lineEdit_inputNum = new QLineEdit(pageGame);
        lineEdit_inputNum->setObjectName(QString::fromUtf8("lineEdit_inputNum"));
        lineEdit_inputNum->setGeometry(QRect(130, 100, 113, 20));
        lineEdit_inputNum->setMaxLength(5);
        lineEdit_inputNum->setReadOnly(true);
        pushButton_back = new QPushButton(pageGame);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setGeometry(QRect(400, 0, 75, 30));
        stackedWidget->addWidget(pageGame);
        pageWin = new QWidget();
        pageWin->setObjectName(QString::fromUtf8("pageWin"));
        label_win = new QLabel(pageWin);
        label_win->setObjectName(QString::fromUtf8("label_win"));
        label_win->setGeometry(QRect(119, 90, 251, 141));
        label = new QLabel(pageWin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 50, 101, 20));
        label->setFont(font4);
        stackedWidget->addWidget(pageWin);
        pageEnd = new QWidget();
        pageEnd->setObjectName(QString::fromUtf8("pageEnd"));
        gridLayout_2 = new QGridLayout(pageEnd);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget = new QWidget(pageEnd);
        widget->setObjectName(QString::fromUtf8("widget"));
        label_end = new QLabel(widget);
        label_end->setObjectName(QString::fromUtf8("label_end"));
        label_end->setGeometry(QRect(90, 110, 251, 141));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(153, 60, 101, 20));
        label_2->setFont(font4);

        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        stackedWidget->addWidget(pageEnd);

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label_title->setText(QCoreApplication::translate("Widget", "\347\214\234\346\225\260\345\255\227\346\270\270\346\210\217", nullptr));
        pushButton_start->setText(QCoreApplication::translate("Widget", "\350\277\233\345\205\245\346\270\270\346\210\217", nullptr));
        pushButton_end->setText(QCoreApplication::translate("Widget", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
        label_guess->setText(QCoreApplication::translate("Widget", "          \350\257\267\350\256\276\347\275\256\347\214\234\346\225\260\345\255\227\346\227\266\351\227\264(\347\247\222)", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Widget", "20", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Widget", "40", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Widget", "60", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Widget", "80", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("Widget", "100", nullptr));

        pushButton_num0->setText(QCoreApplication::translate("Widget", "0", nullptr));
        pushButton_num1->setText(QCoreApplication::translate("Widget", "1", nullptr));
        pushButton_num2->setText(QCoreApplication::translate("Widget", "2", nullptr));
        pushButton_num3->setText(QCoreApplication::translate("Widget", "3", nullptr));
        pushButton_num4->setText(QCoreApplication::translate("Widget", "4", nullptr));
        pushButton_num5->setText(QCoreApplication::translate("Widget", "5", nullptr));
        pushButton_num6->setText(QCoreApplication::translate("Widget", "6", nullptr));
        pushButton_num7->setText(QCoreApplication::translate("Widget", "7", nullptr));
        pushButton_num8->setText(QCoreApplication::translate("Widget", "8", nullptr));
        pushButton_num9->setText(QCoreApplication::translate("Widget", "9", nullptr));
        pushButton_numComplete->setText(QCoreApplication::translate("Widget", "\342\234\224", nullptr));
        pushButton_numDelete->setText(QCoreApplication::translate("Widget", "\303\227", nullptr));
        label_process->setText(QCoreApplication::translate("Widget", "\346\227\266\351\227\264\350\277\233\345\272\246", nullptr));
        label_inputNum->setText(QCoreApplication::translate("Widget", "\350\276\223\345\205\2451-10000\346\225\260\345\255\227:", nullptr));
        pushButton_numTip->setText(QCoreApplication::translate("Widget", "\346\217\220\347\244\272", nullptr));
        pushButton_back->setText(QCoreApplication::translate("Widget", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", nullptr));
        label_win->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\346\201\255\345\226\234\344\275\240\357\274\214\347\214\234\345\257\271\345\225\246!", nullptr));
        label_end->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\345\276\210\351\201\227\346\206\276,\346\227\266\351\227\264\347\273\223\346\235\237!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
