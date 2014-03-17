#include "CScaleEventFilter.h"
#include "CMainWindow.h"
#include <QMainWindow>
#include <QMouseEvent>

#define SIZE_LEFT 10
#define SIZE_RIGHT 10
#define SIZE_TOP 10
#define SIZE_BOTTOM 10

bool CScaleEventFilter::eventFilter(QObject *obj, QEvent *event)
{
	m_pMainWindow = (QMainWindow *)obj;
	
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

void CScaleEventFilter::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_posInWindow = event->globalPos() - m_pMainWindow->frameGeometry().topLeft();
		m_bLeftButtonDown = true;
	}
}

void CScaleEventFilter::mouseMoveEvent(QMouseEvent *event)
{
	QPoint pos = m_pMainWindow->mapTo(m_pMainWindow, event->pos());

	if (m_bLeftButtonDown == true)
	{
		m_pMainWindow->move(event->globalPos() - m_posInWindow);
	}

	m_pMainWindow->setCursor(Qt::ArrowCursor);
	m_bOnLeft = false;
	m_bOnRight = false;
	m_bOnTop = false;
	m_bOnBottom = false;
	if (pos.x() < SIZE_LEFT) m_bOnLeft = true;
	if (pos.x() > m_pMainWindow->width()-SIZE_RIGHT) m_bOnRight = true;
	if (pos.y() < SIZE_TOP) m_bOnTop = true;
	if (pos.y() > m_pMainWindow->height()-SIZE_BOTTOM) m_bOnBottom = true;
	if (m_bOnLeft && m_bOnTop) m_pMainWindow->setCursor(Qt::SizeFDiagCursor);
	else if (m_bOnLeft && m_bOnBottom) m_pMainWindow->setCursor(Qt::SizeBDiagCursor);
	else if (m_bOnRight && m_bOnTop) m_pMainWindow->setCursor(Qt::SizeBDiagCursor);
	else if (m_bOnRight && m_bOnBottom) m_pMainWindow->setCursor(Qt::SizeFDiagCursor);
	else if (m_bOnLeft) m_pMainWindow->setCursor(Qt::SizeHorCursor);
	else if (m_bOnRight) m_pMainWindow->setCursor(Qt::SizeHorCursor);
	else if (m_bOnTop) m_pMainWindow->setCursor(Qt::SizeVerCursor);
	else if (m_bOnBottom) m_pMainWindow->setCursor(Qt::SizeVerCursor);
}

void CScaleEventFilter::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_bLeftButtonDown = false;
	}
}
