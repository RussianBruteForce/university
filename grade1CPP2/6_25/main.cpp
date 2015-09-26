#include "mt.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MT w;
	w.show();

	return a.exec();
}
