#pragma once
#include <qwidget.h>
#include <QPushButton>
// ×Ó½çÃæ
class SubWidget :public QWidget {
	Q_OBJECT
public:
	SubWidget(QWidget *parent = nullptr);
public slots:
	void sendSlot();
private:
	QPushButton b1;
signals:
	void mysignal();
};
