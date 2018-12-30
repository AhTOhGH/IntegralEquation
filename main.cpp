#include "IntegralEquation.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	IntegralEquation w;
	w.showMaximized();
	return a.exec();
}
