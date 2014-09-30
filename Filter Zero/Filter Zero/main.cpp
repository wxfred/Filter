#include "CMainWindow.h"
#include "GBlankWindow.h"
#include "CScaleEventFilter.h"
#include "CWidgetShadowPainter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//CMainWindow w;
	GBlankWindow w;
	GWidgetGlowingLight *m_pWidgetGlowingLight = new GWidgetGlowingLight(&w);
	CWidgetShadowPainter *m_pWidgetShadowPainter = new CWidgetShadowPainter();
	w.installEventFilter(new CScaleEventFilter(&w));
	w.setWidgetShadowPainter(m_pWidgetShadowPainter);
	a.installEventFilter(m_pWidgetGlowingLight);
	//w.setWidgetGlowingLight(m_pWidgetGlowingLight);
	w.show();
	return a.exec();
}
