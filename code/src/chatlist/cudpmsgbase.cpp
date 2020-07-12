#include "cudpmsgbase.h"

CUdpMsgBase::CUdpMsgBase(QObject *parent)
	: QObject(parent)
{

}

CUdpMsgBase::~CUdpMsgBase()
{

}

void CUdpMsgBase::DataHanding(const char* data)
{
	int msgType = MSG_NONE;
	::memcpy(&msgType, data, sizeof(int));

	if (msgType == MSG_NONE)
	{
		
	}

	if (msgType == MSG_CHANGEMOUSEPOS)
	{
		emit changepos();
	}

	return;

}
