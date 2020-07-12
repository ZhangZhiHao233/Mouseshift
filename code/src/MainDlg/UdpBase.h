/*****************************************************
 Author: ��־��
 Mail: 791745123@qq.com
 Time: 2019-1-5
 Function:
	UDPͨ�Ż���
 Version: v 1.0
*****************************************************/


#pragma once
#include <Windows.h>
#pragma comment(lib, "ws2_32.lib")

#define max_data_length 1024
class CUdpBase
{
public:
	CUdpBase(void);
	virtual ~CUdpBase(void);

	//��������ʼ��
	void ServerInit(int port);
	//�㲥����
	int SendData(const char* data, int size, int port);
	//ָ��IP����
	int SendData(const char* data, int size, int port, const char* ip);

	//���ݴ�����������д
	virtual void DataHanding(const char* data);

private:
	//��ʼ��Ŀ��������ַ
	void destHostInit(int port);
	//��ʼ��Ŀ��������ַ
	void destHostInit(int port, const char* ip);
	//���������߳�
	static DWORD WINAPI RecvThread(LPVOID lparam);

	//�����׽���
	SOCKET m_listenSocket;
	//�����׽���
	SOCKET m_sendSocket;
	//Ŀ��������ַ
	SOCKADDR_IN m_destHost;

public:
	//���Ͷ��׽����Ƿ񴴽�(�㲥)
	bool m_bSendSocketInitBroad;
	//���Ͷ��׽����Ƿ񴴽�(ָ��)
	bool m_bSendSocketInitSpecial;
};

