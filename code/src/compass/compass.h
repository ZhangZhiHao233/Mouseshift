#ifndef COMPASS_H
#define COMPASS_H

#include <QtWidgets/QMainWindow>
#include "ui_compass.h"
#include "cudpmsgbase.h"

class compass : public QMainWindow
{
	Q_OBJECT

public:
	compass(QWidget *parent = 0);
	~compass();

private:
	Ui::compassClass ui;
	CUdpMsgBase m_myudp;

protected:
	void keyPressEvent(QKeyEvent * event);
	void mousePressEvent(QMouseEvent * event);

private slots:
	void changePos();
};

#endif // COMPASS_H
