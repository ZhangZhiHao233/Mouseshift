#include "maindlg.h"
#include <QDebug>
#include <QkeyEvent>

MainDlg::MainDlg(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_myudp.ServerInit(PORT_MAINDLG);
	connect(&m_myudp, SIGNAL(changepos()), this, SLOT(changePos()));
}

MainDlg::~MainDlg()
{

}


void MainDlg::changePos()
{
	HWND hwnd = ::FindWindow(NULL, L"MainDlg");
	::SetForegroundWindow(hwnd);
	

	HWND hForeWnd = ::GetForegroundWindow();

	DWORD dcurid = ::GetCurrentThreadId();
	DWORD dfoid = ::GetWindowThreadProcessId(hForeWnd, NULL);

	::AttachThreadInput(dcurid, dfoid, TRUE);	

	QRect rect = this->geometry();
	SetCursorPos(rect.left() + 200, rect.top() + 200);
}

void MainDlg::keyPressEvent(QKeyEvent * event)
{
	switch(event->key())
	{
	case Qt::Key_J:
		{
			CInfoBase m_sendMsg;
			m_sendMsg.infoType = MSG_CHANGEMOUSEPOS;
			m_sendMsg.senderType = PROCESS_MAINDLG;

			m_myudp.SendData((char*)&m_sendMsg, sizeof(m_sendMsg), PORT_COMPASS, "127.0.0.1");
			break;
		}
	default:
		{

		}
	}
}

void MainDlg::mousePressEvent(QMouseEvent * event)
{
	qDebug()<<"mouse";

}
