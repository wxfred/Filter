#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QtWidgets/QMainWindow.h>
#include "ui_MainWindow.h"

class CMainWindow : public QMainWindow, Ui::MainWindowClass
{
	Q_OBJECT

public:
	CMainWindow(QWidget *parent = 0);
	~CMainWindow();

private:
};

#endif // CMAINWINDOW_H
