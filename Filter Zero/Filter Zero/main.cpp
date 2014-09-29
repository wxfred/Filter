#include "CMainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CMainWindow w;
	GWidgetGlowingLight widgetGlowingLight(&w);
	a.installEventFilter(&widgetGlowingLight);
	w.setWidgetGlowingLight(&widgetGlowingLight);
	w.show();
	return a.exec();
}
