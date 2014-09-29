/*
 * GWidgetGlowingLight.h
 *
 *  Created on: 2014-9-29
 *      Author: wxfred
 */

#ifndef G_WIDGET_GLOWING_LIGHT_H
#define G_WIDGET_GLOWING_LIGHT_H

#include <QObject>
#include <QWidget>
#include <QColor>

class GWidgetGlowingLight : public QObject
{
	Q_OBJECT

public:
	GWidgetGlowingLight(QWidget *parent = 0);
	
	void onPaint();

protected:
	bool eventFilter(QObject *obj, QEvent *event);
	void paintGlowingLight(QColor color);

private:
	QWidget*	m_pWidget;
	QColor		m_color;
};

#endif