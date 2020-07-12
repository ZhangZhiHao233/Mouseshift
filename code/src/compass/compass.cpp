#include "compass.h"
#include <QDebug>
#include <QkeyEvent>


compass::compass(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_myudp.ServerInit(PORT_COMPASS);
	connect(&m_myudp, SIGNAL(changepos()), this, SLOT(changePos()));
}

compass::~compass()
{

}

void compass::changePos()
{
	//获取自身窗口句柄并置前
	HWND hwnd = ::FindWindow(NULL, L"compass");
	::SetForegroundWindow(hwnd);

	//获取置前窗口句柄(该步骤可省略，直接用上一步获得的句柄)
	HWND hForeWnd = ::GetForegroundWindow();
	//获取当前工作线程ID
	DWORD dcurid = ::GetCurrentThreadId();
	//获取置前窗口的线程ID
	DWORD dfoid = ::GetWindowThreadProcessId(hForeWnd, NULL);

	//依附
	::AttachThreadInput(dcurid, dfoid, TRUE);	

	//设置鼠标位置
	QRect rect = this->geometry();
	SetCursorPos(rect.left() + 200, rect.top() + 200);
}

void compass::keyPressEvent(QKeyEvent * event)
{
	switch(event->key())
	{
	case Qt::Key_J:
		{
			CInfoBase m_sendMsg;
			m_sendMsg.infoType = MSG_CHANGEMOUSEPOS;
			m_sendMsg.senderType = PROCESS_COMPASS;
			
			m_myudp.SendData((char*)&m_sendMsg, sizeof(m_sendMsg), PORT_CHATLIST, "127.0.0.1");
			break;
		}
	default:
		{

		}
	}
}

void compass::mousePressEvent(QMouseEvent * event)
{
	qDebug()<<"mouse";

}
