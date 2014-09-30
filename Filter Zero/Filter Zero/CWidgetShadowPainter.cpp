/*
 * CWidgetShadowPainter.cpp
 *
 *  Created on: 2014-9-30
 *      Author: wxfred
 */

#include "CWidgetShadowPainter.h"
#include <QPainter>

CWidgetShadowPainter::CWidgetShadowPainter()
{

}

CWidgetShadowPainter::~CWidgetShadowPainter()
{

}

void CWidgetShadowPainter::paint(QWidget *widget, int size)
{
	QPainter painter(widget);
	//QLinearGradient gradient;
	float innerWidth = widget->width() - size - size;
	float innerHeight = widget->height() - size - size;
	QRectF topRect(size, 0.0f, innerWidth, size);
	QRectF rightRect(widget->width()-size, size, size, innerHeight);
	QRectF bottomRect(size, widget->height()-size, innerWidth, size);
	QRectF leftRect(0.0f, size, size, innerHeight);
	int color = Qt::gray;
	painter.fillRect(topRect, color);
	painter.fillRect(rightRect, color);
	painter.fillRect(bottomRect, color);
	painter.fillRect(leftRect, color);
}