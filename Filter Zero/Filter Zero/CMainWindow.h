#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "GWidgetGlowingLight.h"

class CMainWindow : public QMainWindow, Ui::MainWindowClass
{
	Q_OBJECT

public:
	CMainWindow(QWidget *parent = 0);
	~CMainWindow();

	void setWidgetGlowingLight(GWidgetGlowingLight *widgetGlowingLight);

protected:
	void paintEvent(QPaintEvent *event);

private:
	GWidgetGlowingLight*	m_pWidgetGlowingLight;
};

#endif // CMAINWINDOW_H
