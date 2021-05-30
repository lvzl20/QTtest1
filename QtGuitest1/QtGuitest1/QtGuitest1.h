#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuitest1.h"

class QtGuitest1 : public QMainWindow
{
	Q_OBJECT

public:
	QtGuitest1(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtGuitest1Class ui;
};
