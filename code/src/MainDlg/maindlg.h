#ifndef MAINDLG_H
#define MAINDLG_H

#include <QtWidgets/QWidget>
#include "ui_maindlg.h"
#include "cudpmsgbase.h"

class MainDlg : public QWidget
{
	Q_OBJECT

public:
	MainDlg(QWidget *parent = 0);
	~MainDlg();

private:
	Ui::MainDlgClass ui;
	CUdpMsgBase m_myudp;

protected:
	void keyPressEvent(QKeyEvent * event);
	void mousePressEvent(QMouseEvent * event);

private slots:
	void changePos();
};

#endif // MAINDLG_H
