#ifndef CSCALEEVENTFILTER_H
#define CSCALEEVENTFILTER_H

#include <QObject>
#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include <QPoint>

class CScaleEventFilter : public QObject
{
	Q_OBJECT

protected:
	bool eventFilter(QObject *obj, QEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
private:
	QMainWindow* m_pMainWindow;
	QPoint m_posInWindow;
	bool m_bLeftButtonDown;

	bool m_bOnLeft;
	bool m_bOnRight;
	bool m_bOnTop;
	bool m_bOnBottom;
};

#endif