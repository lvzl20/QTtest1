#include "QtGuitest1.h"
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <QWidget>
#include "ParWidget.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ParWidget w;
	w.show();
	return a.exec();
}
