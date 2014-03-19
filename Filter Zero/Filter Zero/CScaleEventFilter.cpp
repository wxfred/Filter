#include "CScaleEventFilter.h"
#include "CMainWindow.h"
#include <QMainWindow>
#include <QMouseEvent>
#include <QRect>

#define REGION_LEFT 10
#define REGION_RIGHT 10
#define REGION_TOP 10
#define REGION_BOTTOM 10

//////////////////////////////////////////////////////////////////////////
// Public method(s)
//////////////////////////////////////////////////////////////////////////

/** Construct method */
CScaleEventFilter::CScaleEventFilter(QMainWindow *parent)
	:QObject(parent)
{
	m_pMainWindow = NULL;
	m_bLeftButtonDown = false;
	m_eWindowRegionUnderMouse = CENTER;
	m_bScalable = true;
}

//////////////////////////////////////////////////////////////////////////
// Protected method(s)
//////////////////////////////////////////////////////////////////////////

/** Override method */
bool CScaleEventFilter::eventFilter(QObject *obj, QEvent *event)
{
	m_pMainWindow = (QMainWindow *)obj;
	
	// Check whether window is scalable 
	m_bScalable = true;
	if (m_pMainWindow->minimumSize() == m_pMainWindow->maximumSize()) m_bScalable = false;
	
	switch (event->type())
	{
	case QEvent::MouseButtonPress:
		mousePressEvent((QMouseEvent *)event);
		break;
	case QEvent::MouseMove:
		mouseMoveEvent((QMouseEvent *)event);
		break;
	case QEvent::MouseButtonRelease:
		mouseReleaseEvent((QMouseEvent *)event);
		break;
	}

	return false;
}

/**
 * 
 */
void CScaleEventFilter::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_posInWindow = event->globalPos() - m_pMainWindow->frameGeometry().topLeft();
		m_eWindowRegionUnderMouse = windowRegion(m_posInWindow);
		m_bLeftButtonDown = true;
	}
}

/**
 * 
 */
void CScaleEventFilter::mouseMoveEvent(QMouseEvent *event)
{
	QPoint pos = m_pMainWindow->mapTo(m_pMainWindow, event->pos());

	if (m_bLeftButtonDown == false)
	{
		EWindowRegion region = windowRegion(pos);
		setCursor(region);
	}
	else
	{
		QRect geometry = m_pMainWindow->geometry();
		QPoint globalPos = event->globalPos();
		int minWidth = m_pMainWindow->minimumWidth();
		int maxWidth = m_pMainWindow->maximumWidth();
		int minHeight = m_pMainWindow->minimumHeight();
		int maxHeight = m_pMainWindow->maximumHeight();
		int left, top, right, bottom;

		switch (m_eWindowRegionUnderMouse)
		{
		case TOP_LEFT:
			left = globalPos.x();
			top = globalPos.y();
			if (geometry.right()-left+1 < minWidth) left = geometry.right() - minWidth + 1;
			if (geometry.right()-left+1 > maxWidth) left = geometry.right() - maxWidth + 1;
			if (geometry.bottom()-top+1 < minHeight) top = geometry.bottom() - minHeight + 1;
			if (geometry.bottom()-top+1 > maxHeight) top = geometry.bottom() - maxHeight + 1;
			geometry.setTopLeft(QPoint(left, top));
			break;
		case TOP:
			top = globalPos.y();
			if (geometry.bottom()-top+1 < minHeight) top = geometry.bottom() - minHeight + 1;
			if (geometry.bottom()-top+1 > maxHeight) top = geometry.bottom() - maxHeight + 1;
			geometry.setTop(top);
			break;
		case TOP_RIGHT:
			top = globalPos.y();
			if (geometry.bottom()-top+1 < minHeight) top = geometry.bottom() - minHeight + 1;
			if (geometry.bottom()-top+1 > maxHeight) top = geometry.bottom() - maxHeight + 1;
			geometry.setTopRight(QPoint(globalPos.x(), top));
			break;
		case RIGHT:
			geometry.setRight(globalPos.x());
			break;
		case BOTTOM_RIGHT:
			geometry.setBottomRight(QPoint(globalPos.x(), globalPos.y()));
			break;
		case BOTTOM:
			geometry.setBottom(globalPos.y());
			break;
		case BOTTOM_LEFT:
			left = globalPos.x();
			if (geometry.right()-left+1 < minWidth) left = geometry.right() - minWidth + 1;
			if (geometry.right()-left+1 > maxWidth) left = geometry.right() - maxWidth + 1;
			geometry.setBottomLeft(QPoint(left, globalPos.y()));
			break;
		case LEFT:
			left = globalPos.x();
			if (geometry.right()-left+1 < minWidth) left = geometry.right() - minWidth + 1;
			if (geometry.right()-left+1 > maxWidth) left = geometry.right() - maxWidth + 1;
			geometry.setLeft(left);
			break;
		case CENTER:
			geometry.moveTo(globalPos-m_posInWindow);
			break;
		}
		m_pMainWindow->setGeometry(geometry);
	}
}

/**
 * 
 */
void CScaleEventFilter::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_bLeftButtonDown = false;
	}
}

/**
 * 
 */
EWindowRegion CScaleEventFilter::windowRegion(QPoint pos)
{
	bool onLeft = false;
	bool onRight = false;
	bool onTop = false;
	bool onBottom = false;

	if (pos.x() < REGION_LEFT) onLeft = true;
	if (pos.x() > m_pMainWindow->width()-REGION_RIGHT) onRight = true;
	if (pos.y() < REGION_TOP) onTop = true;
	if (pos.y() > m_pMainWindow->height()-REGION_BOTTOM) onBottom = true;

	if (onLeft && onTop) return TOP_LEFT;
	if (onLeft && onBottom) return BOTTOM_LEFT;
	if (onRight && onTop) return TOP_RIGHT;
	if (onRight && onBottom) return BOTTOM_RIGHT;
	if (onLeft) return LEFT;
	if (onRight) return RIGHT;
	if (onTop) return TOP;
	if (onBottom) return BOTTOM;
	return CENTER;
}

/**
 * 
 */
void CScaleEventFilter::setCursor(EWindowRegion region)
{
	switch (region)
	{
	case TOP_LEFT:
	case BOTTOM_RIGHT:
		if (m_bScalable == false) break;
		m_pMainWindow->setCursor(Qt::SizeFDiagCursor);
		break;
	case TOP:
	case BOTTOM:
		if (m_bScalable == false) break;
		m_pMainWindow->setCursor(Qt::SizeVerCursor);
		break;
	case TOP_RIGHT:
	case BOTTOM_LEFT:
		if (m_bScalable == false) break;
		m_pMainWindow->setCursor(Qt::SizeBDiagCursor);
		break;
	case RIGHT:
	case LEFT:
		if (m_bScalable == false) break;
		m_pMainWindow->setCursor(Qt::SizeHorCursor);
		break;
	case CENTER:
		m_pMainWindow->setCursor(Qt::ArrowCursor);
		break;
	}
}