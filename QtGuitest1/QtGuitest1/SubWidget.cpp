#include "SubWidget.h"
SubWidget::SubWidget(QWidget *parent) : QWidget(parent) {
	resize(400, 300);
	b1.setText(QStringLiteral("��ת��������"));
	b1.setParent(this);
	b1.move(100, 100);
	setWindowTitle(QStringLiteral("�ӽ���"));
	connect(&b1, &QPushButton::clicked, this, &SubWidget::sendSlot);
}

void SubWidget::sendSlot() {
	emit mysignal();
}