#include "CMainWindow.h"
#include "CScaleEventFilter.h"
#include <QPainter>
#include <QMouseEvent>

#define SIZE_LEFT 10
#define SIZE_RIGHT 10
#define SIZE_TOP 10
#define SIZE_BOTTOM 10

// Constructor
CMainWindow::CMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground, true);

	installEventFilter(new CScaleEventFilter());

	//setFixedSize(800, 600);
}

// Destructor
CMainWindow::~CMainWindow()
{

}

void CMainWindow::setWidgetGlowingLight(GWidgetGlowingLight *widgetGlowingLight)
{
	m_pWidgetGlowingLight = widgetGlowingLight;
}

///////////////////////////////////////////////////////////////
// Protected method(s)
///////////////////////////////////////////////////////////////
void CMainWindow::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.setBrush(Qt::white);
	painter.drawRect(-1, -1, this->width()+1, this->height()+1);

	if (m_pWidgetGlowingLight) m_pWidgetGlowingLight->onPaint();
}