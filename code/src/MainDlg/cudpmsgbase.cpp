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
	emit changepos(QString(QLatin1String(data)));
}
