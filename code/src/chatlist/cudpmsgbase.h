/*****************************************************
 Author: ��־��
 Mail: 791745123@qq.com
 Time: 2019-1-5
 Function:
	UDP��Ϣ�������
 Version: v 1.0
*****************************************************/
#ifndef CUDPMSGBASE_H
#define CUDPMSGBASE_H

#include <QObject>
#include "UdpBase.h"
#include "CInfoBase.h"

class CUdpMsgBase : public QObject, public CUdpBase
{
	Q_OBJECT

public:
	CUdpMsgBase(QObject *parent = 0);
	~CUdpMsgBase();

	virtual void DataHanding(const char* data);
private:

signals:
	void changepos();
};

#endif // CUDPMSGBASE_H
