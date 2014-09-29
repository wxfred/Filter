/*
 * GWidgetGlowingLight.cpp
 *
 *  Created on: 2014-9-29
 *      Author: wxfred
 */

#include "GWidgetGlowingLight.h"
#include <QFocusEvent>
#include <QPainter>

GWidgetGlowingLight::GWidgetGlowingLight(QWidget *parent)
	:QObject(parent)
{
	m_pWidget = parent;
	m_color = Qt::white;
}

void GWidgetGlowingLight::onPaint()
{
	paintGlowingLight(m_color);
}

//////////////////////////////////////////////////////////////////////////

/** Override method */
bool GWidgetGlowingLight::eventFilter(QObject *obj, QEvent *event)
{
	//if (obj != m_pWidget) return true;

	switch (event->type())
	{
	case QEvent::ApplicationActivate:
		m_color = Qt::blue;
		m_pWidget->update();
		break;
	case QEvent::ApplicationDeactivate:
		m_color = Qt::gray;
		m_pWidget->update();
		break;
	}

	return false;
}

void GWidgetGlowingLight::paintGlowingLight(QColor color)
{
	QPainter painter(m_pWidget);
	painter.setBrush(color);
	painter.drawRect(-1, -1, m_pWidget->width()+1, m_pWidget->height()+1);
	m_pWidget->update();
}