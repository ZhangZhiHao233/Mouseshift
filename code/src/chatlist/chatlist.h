#ifndef CHATLIST_H
#define CHATLIST_H

#include <QtWidgets/QMainWindow>
#include "ui_chatlist.h"
#include "cudpmsgbase.h"

class chatlist : public QMainWindow
{
	Q_OBJECT

public:
	chatlist(QWidget *parent = 0);
	~chatlist();

private:
	Ui::chatlistClass ui;
	CUdpMsgBase m_myudp;

protected:
	void keyPressEvent(QKeyEvent * event);
	void mousePressEvent(QMouseEvent * event);

private slots:
		void changePos();
};

#endif // CHATLIST_H
