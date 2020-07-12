#include "chatlist.h"
#include <QDebug>
#include <QKeyEvent>

chatlist::chatlist(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_myudp.ServerInit(PORT_CHATLIST);
	connect(&m_myudp, SIGNAL(changepos()), this, SLOT(changePos()));
}

chatlist::~chatlist()
{

}


void chatlist::changePos()
{
	HWND hwnd = ::FindWindow(NULL, L"chatlist");
	::SetForegroundWindow(hwnd);


	HWND hForeWnd = ::GetForegroundWindow();

	DWORD dcurid = ::GetCurrentThreadId();
	DWORD dfoid = ::GetWindowThreadProcessId(hForeWnd, NULL);

	::AttachThreadInput(dcurid, dfoid, TRUE);	

	QRect rect = this->geometry();
	SetCursorPos(rect.left() + 200, rect.top() + 200);
}

void chatlist::keyPressEvent(QKeyEvent * event)
{
	switch(event->key())
	{
	case Qt::Key_J:
		{
			CInfoBase m_sendMsg;
			m_sendMsg.infoType = MSG_CHANGEMOUSEPOS;
			m_sendMsg.senderType = PROCESS_CHATLIST;

			m_myudp.SendData((char*)&m_sendMsg, sizeof(m_sendMsg), PORT_MAINDLG, "127.0.0.1");
			break;
		}
	default:
		{

		}
	}
}

void chatlist::mousePressEvent(QMouseEvent * event)
{
	qDebug()<<"mouse";

}