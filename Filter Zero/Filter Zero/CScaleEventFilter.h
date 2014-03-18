#ifndef CSCALEEVENTFILTER_H
#define CSCALEEVENTFILTER_H

#include <QObject>
#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include <QPoint>

enum EWindowRegion
{
	TOP_LEFT,
	TOP,
	TOP_RIGHT,
	RIGHT,
	BOTTOM_RIGHT,
	BOTTOM,
	BOTTOM_LEFT,
	LEFT,
	CENTER
};

class CScaleEventFilter : public QObject
{
	Q_OBJECT

public:
	CScaleEventFilter(QMainWindow *parent = 0);

protected:
	bool eventFilter(QObject *obj, QEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	EWindowRegion windowRegion(QPoint pos);
	void setCursor(EWindowRegion region);
private:
	QMainWindow*	m_pMainWindow;
	QPoint			m_posInWindow;
	bool			m_bLeftButtonDown;
	EWindowRegion	m_eWindowRegionUnderMouse;
};

#endif