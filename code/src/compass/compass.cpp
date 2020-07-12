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
	//��ȡ�����ھ������ǰ
	HWND hwnd = ::FindWindow(NULL, L"compass");
	::SetForegroundWindow(hwnd);

	//��ȡ��ǰ���ھ��(�ò����ʡ�ԣ�ֱ������һ����õľ��)
	HWND hForeWnd = ::GetForegroundWindow();
	//��ȡ��ǰ�����߳�ID
	DWORD dcurid = ::GetCurrentThreadId();
	//��ȡ��ǰ���ڵ��߳�ID
	DWORD dfoid = ::GetWindowThreadProcessId(hForeWnd, NULL);

	//����
	::AttachThreadInput(dcurid, dfoid, TRUE);	

	//�������λ��
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
