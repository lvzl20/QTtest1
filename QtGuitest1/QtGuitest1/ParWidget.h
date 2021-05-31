#pragma once
#include <qwidget.h>
#include <QPushButton>
#include "SubWidget.h"
class ParWidget :public QWidget {
	Q_OBJECT
public:
	ParWidget(QWidget *parent = nullptr);
	void JumSub();
	void BackPar();
private:
	QPushButton b1;
	//QPushButton *b2;
	SubWidget w;
};

