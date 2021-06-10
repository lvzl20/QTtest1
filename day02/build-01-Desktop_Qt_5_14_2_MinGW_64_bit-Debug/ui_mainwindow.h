/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionda;
    QAction *actionda2;
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *pushButton;
    QWidget *page_2;
    QPushButton *pushButton_2;
    QPushButton *change1;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QProgressBar *progressBar1;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QSplitter *splitter;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(635, 363);
        actionda = new QAction(MainWindow);
        actionda->setObjectName(QString::fromUtf8("actionda"));
        actionda2 = new QAction(MainWindow);
        actionda2->setObjectName(QString::fromUtf8("actionda2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(380, 50, 201, 71));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 30, 75, 23));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 50, 75, 23));
        stackedWidget->addWidget(page_2);
        change1 = new QPushButton(centralwidget);
        change1->setObjectName(QString::fromUtf8("change1"));
        change1->setGeometry(QRect(430, 20, 75, 23));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 30, 311, 81));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit1 = new QLineEdit(frame);
        lineEdit1->setObjectName(QString::fromUtf8("lineEdit1"));

        gridLayout->addWidget(lineEdit1, 1, 1, 1, 1);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 2, 1, 1);

        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 120, 81, 21));
        label_3->setOpenExternalLinks(true);
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(20, 150, 301, 41));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        progressBar1 = new QProgressBar(frame_2);
        progressBar1->setObjectName(QString::fromUtf8("progressBar1"));
        progressBar1->setValue(24);

        gridLayout_2->addWidget(progressBar1, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(frame_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_2->addWidget(lineEdit_2, 0, 1, 1, 1);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 2, 1, 1);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(40, 180, 512, 192));
        splitter->setOrientation(Qt::Horizontal);
        textEdit = new QTextEdit(splitter);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        splitter->addWidget(textEdit);
        textEdit_2 = new QTextEdit(splitter);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        splitter->addWidget(textEdit_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 635, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionda);
        menu->addAction(actionda2);

        retranslateUi(MainWindow);
        QObject::connect(actionda, SIGNAL(triggered()), lineEdit, SLOT(clear()));
        QObject::connect(actionda2, SIGNAL(triggered()), lineEdit1, SLOT(cut()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionda->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\347\274\226\350\276\221\346\241\2061", nullptr));
        actionda2->setText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207\347\274\226\350\276\221\346\241\2062\351\200\211\344\270\255\345\206\205\345\256\271", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\351\241\265\351\235\2421", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\351\241\265\351\235\2422", nullptr));
        change1->setText(QCoreApplication::translate("MainWindow", "\345\210\207\346\215\242\351\241\265\351\235\242", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221\346\241\2062", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221\346\241\2061", nullptr));
        lineEdit1->setText(QCoreApplication::translate("MainWindow", "1234", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "12344", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\346\214\211\344\270\200\344\270\213\346\230\276\347\244\272\345\234\250\347\274\226\350\276\221\346\241\2062", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\350\276\223\345\205\2450-100\346\230\276\347\244\272\350\277\233\345\272\246", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
