#include "chatlist.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	chatlist w;
	w.show();
	return a.exec();
}
