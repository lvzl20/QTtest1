#include "SubWidget.h"
SubWidget::SubWidget(QWidget *parent) : QWidget(parent) {
	resize(400, 300);
	b1.setText(QStringLiteral("跳转到主界面"));
	b1.setParent(this);
	b1.move(100, 100);
	setWindowTitle(QStringLiteral("子界面"));
	connect(&b1, &QPushButton::clicked, this, &SubWidget::sendSlot);
}

void SubWidget::sendSlot() {
	emit mysignal();
}