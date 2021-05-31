#include "ParWidget.h"
ParWidget::ParWidget(QWidget *parent) :QWidget(parent) {
	resize(400, 300);
	b1.setText(QStringLiteral("跳转到子界面"));
	b1.move(100, 100);
	b1.setParent(this);

	//w.setParent(this);
	this->setWindowTitle(QStringLiteral("主界面"));
	connect(&b1, &QPushButton::released, this, &ParWidget::JumSub);
	connect(&w, &SubWidget::mysignal, this, &ParWidget::BackPar);
}

void ParWidget::JumSub() {
	this->hide();
	w.show();
}

void ParWidget::BackPar() {
	this->show();
	w.hide();
}