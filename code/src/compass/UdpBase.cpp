#include "UdpBase.h"
#include <stdio.h>


CUdpBase::CUdpBase(void)
{
	m_bSendSocketInitBroad = false;
	m_bSendSocketInitSpecial = false;
}


CUdpBase::~CUdpBase(void)
{
}

void CUdpBase::ServerInit(int port)
{
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR)
	{
		return;
	}

	//等待数据到来
	//BOOL _bBroadcast = TRUE;
	m_listenSocket = socket(AF_INET, SOCK_DGRAM, 0);

	SOCKADDR_IN _addr;
	_addr.sin_family = AF_INET;
	_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	_addr.sin_port = htons(port);
	if(bind(m_listenSocket, (SOCKADDR*)&_addr, sizeof(_addr)) == SOCKET_ERROR)
	{
		return;
	}

	//创建数据接受线程
	HANDLE _thread = CreateThread(NULL, 0, RecvThread, (LPVOID)this, 0, NULL);
	if (_thread == NULL)
	{
		
	}

	CloseHandle(_thread);
}

int CUdpBase::SendData(const char* data, int size, int port)
{
	destHostInit(port);
	int _err = sendto(m_sendSocket, data, size, 0, (SOCKADDR*)&m_destHost, sizeof(SOCKADDR_IN));
	if (_err == SOCKET_ERROR)
	{
		//打印错误消息
		char _msg[1024] = {0};
		sprintf_s(_msg, sizeof(_msg), "sendto error: %d %d %d", GetLastError(), WSAGetLastError(), port);
		OutputDebugStringA(_msg);

		closesocket(m_sendSocket);
		WSACleanup();

		m_bSendSocketInitBroad = false;
		destHostInit(port);
	}

	return _err;
}

int CUdpBase::SendData(const char* data, int size, int port, const char* ip)
{
	destHostInit(port, ip);
	int _err = sendto(m_sendSocket, data, size, 0, (SOCKADDR*)&m_destHost, sizeof(SOCKADDR_IN));
	if (_err == SOCKET_ERROR)
	{
		//打印错误消息
		char _msg[1024] = {0};
		sprintf_s(_msg, sizeof(_msg), "sendto error: %d %d %d", GetLastError(), WSAGetLastError(), port);
		OutputDebugStringA(_msg);

		closesocket(m_sendSocket);
		WSACleanup();

		m_bSendSocketInitSpecial = false;
		destHostInit(port, ip);
	}
	return _err;
}

void CUdpBase::DataHanding(const char* data)
{

}

void CUdpBase::destHostInit(int port)
{
	if (!m_bSendSocketInitBroad)
	{
		WSADATA wsaData;
		int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (iResult != NO_ERROR)
		{
			return;
		}

		BOOL _bBroadcast = TRUE;
		this->m_sendSocket = socket(PF_INET, SOCK_DGRAM, 0);
		setsockopt(this->m_sendSocket, SOL_SOCKET, SO_BROADCAST, (char*)&_bBroadcast, sizeof(BOOL));

		m_destHost.sin_family = AF_INET;
		m_destHost.sin_addr.s_addr = htonl(INADDR_BROADCAST);

		m_bSendSocketInitBroad = true;
	}

	m_destHost.sin_port = htons(port);
}

void CUdpBase::destHostInit(int port, const char* ip)
{
	if (!m_bSendSocketInitSpecial)
	{
		WSADATA wsaData;
		int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (iResult != NO_ERROR)
		{
			return;
		}

		this->m_sendSocket = socket(PF_INET, SOCK_DGRAM, 0);

		m_destHost.sin_family = AF_INET;

		m_bSendSocketInitSpecial = true;
	}

	m_destHost.sin_addr.s_addr = inet_addr(ip);
	m_destHost.sin_port = htons(port);
}

DWORD WINAPI CUdpBase::RecvThread(LPVOID lparam)
{
	CUdpBase* _thisPtr = (CUdpBase*)lparam;
	int _Recv;
	while(true)
	{
		char _buff[max_data_length] = {0};

		SOCKADDR_IN _sockAddr;
		int _sockAddrSize = sizeof(_sockAddr);
		if (recvfrom(_thisPtr->m_listenSocket, _buff, max_data_length, 0, (SOCKADDR*)&_sockAddr, &_sockAddrSize) == SOCKET_ERROR)
		{
			//打印错误消息
			char _msg[1024] = {0};
			sprintf_s(_msg, sizeof(_msg), "recvfrom error: %d %d", GetLastError(), WSAGetLastError());
			OutputDebugStringA(_msg);
			break;
		}

		//进一步处理消息
		_thisPtr->DataHanding(_buff);
		memset(_buff, 0, max_data_length);
	}

	return 0;
}
