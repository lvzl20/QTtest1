/********************************************************************************
** Form generated from reading UI file 'QtGuitest1.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUITEST1_H
#define UI_QTGUITEST1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuitest1Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuitest1Class)
    {
        if (QtGuitest1Class->objectName().isEmpty())
            QtGuitest1Class->setObjectName(QString::fromUtf8("QtGuitest1Class"));
        QtGuitest1Class->resize(600, 400);
        menuBar = new QMenuBar(QtGuitest1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QtGuitest1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuitest1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtGuitest1Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtGuitest1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtGuitest1Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtGuitest1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtGuitest1Class->setStatusBar(statusBar);

        retranslateUi(QtGuitest1Class);

        QMetaObject::connectSlotsByName(QtGuitest1Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuitest1Class)
    {
        QtGuitest1Class->setWindowTitle(QCoreApplication::translate("QtGuitest1Class", "QtGuitest1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuitest1Class: public Ui_QtGuitest1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUITEST1_H
