#include <QtWidgets/QApplication>

#include "testview.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	testview w;
	w.show();
	return app.exec();
}
