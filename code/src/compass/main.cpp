#include "compass.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	compass w;
	w.show();
	return a.exec();
}
