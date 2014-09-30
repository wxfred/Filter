/*
 * GBlankWindow.cpp
 *
 *  Created on: 2014-9-30
 *      Author: wxfred
 */

#include "GBlankWindow.h"
#include <QPainter>

GBlankWindow::GBlankWindow(QWidget *parent)
	: QMainWindow(parent)
{
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground, true);

	this->setMouseTracking(true);
	m_pCentralWidget = new QWidget(this);
	m_pCentralWidget->setObjectName(QStringLiteral("m_pCentralWidget"));
	m_pCentralWidget->setMouseTracking(true);
	//this->setCentralWidget(m_pCentralWidget);

	m_pWidgetShadowPainter = NULL;

	resize(800, 600);
}

GBlankWindow::~GBlankWindow()
{

}

///////////////////////////////////////////////////////////////
// Protected method(s)
///////////////////////////////////////////////////////////////
void GBlankWindow::resizeEvent(QResizeEvent *event)
{
	m_pCentralWidget->setGeometry(m_shadowSize, m_shadowSize, this->width()-2*m_shadowSize, this->height()-2*m_shadowSize);
}

void GBlankWindow::paintEvent(QPaintEvent *event)
{
	int size = 5;

	QPainter painter(this);
	painter.setBrush(Qt::white);
	painter.fillRect(QRectF(size, size, this->width()-2*size, this->height()-2*size), Qt::white);

// 	QPalette palette;
// 	palette.setBrush(QPalette::Background, Qt::blue);
// 	m_pCentralWidget->setPalette(palette);
// 	m_pCentralWidget->setAutoFillBackground(true);

	// draw shadow
	if (m_pWidgetShadowPainter)
	{
		m_pWidgetShadowPainter->paint(this, size);
	}
}