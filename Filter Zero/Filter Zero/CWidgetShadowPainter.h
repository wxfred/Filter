/*
 * CWidgetShadowPainter.h
 *
 *  Created on: 2014-9-30
 *      Author: wxfred
 */

#ifndef CWIDGETSHADOWPAINTER_H
#define CWIDGETSHADOWPAINTER_H

#include "GBlankWindow.h"

class CWidgetShadowPainter : public IWidgetShadowPainter
{
public:
	CWidgetShadowPainter();
	~CWidgetShadowPainter();

	void paint(QWidget *widget, int size);
};

#endif