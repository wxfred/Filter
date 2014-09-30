/*
 * GBlankWindow.h
 *
 *  Created on: 2014-9-30
 *      Author: wxfred
 */

#ifndef GBLANKWINDOW_H
#define GBLANKWINDOW_H

#include <QtWidgets/QMainWindow>

class IWidgetShadowPainter
{
public:
	virtual ~IWidgetShadowPainter(){};

	virtual void paint(QWidget *widget, int size) = 0;
};

class GBlankWindow : public QMainWindow
{
	Q_OBJECT

public:
	GBlankWindow(QWidget *parent = 0);
	~GBlankWindow();

	// Getter(s)
	int getShadowSize() {return m_shadowSize;}

	// Setter(s)
	void setWidgetShadowPainter(IWidgetShadowPainter *widgetShadowPainter) {m_pWidgetShadowPainter = widgetShadowPainter;}
	void setShadowSize(int shadowSize) {m_shadowSize = shadowSize;}

protected:
	void resizeEvent(QResizeEvent *event);
	void paintEvent(QPaintEvent *event);

private:
	IWidgetShadowPainter*	m_pWidgetShadowPainter;
	int						m_shadowSize;

	QWidget*				m_pCentralWidget;
};

#endif