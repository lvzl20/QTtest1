#include "QtGuitest1.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtGuitest1 w;
	w.show();
	return a.exec();
}
