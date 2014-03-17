#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

class CMainWindow : public QMainWindow, Ui::MainWindowClass
{
	Q_OBJECT

public:
	CMainWindow(QWidget *parent = 0);
	~CMainWindow();

protected:
	void paintEvent(QPaintEvent *event);

private:

};

#endif // CMAINWINDOW_H
