/*****************************************************
 Author: 张志浩
 Mail: 791745123@qq.com
 Time: 2019-1-5
 Function:
	UDP通信基类
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

	//服务器初始化
	void ServerInit(int port);
	//广播发送
	int SendData(const char* data, int size, int port);
	//指定IP发送
	int SendData(const char* data, int size, int port, const char* ip);

	//数据处理，供子类重写
	virtual void DataHanding(const char* data);

private:
	//初始化目标主机地址
	void destHostInit(int port);
	//初始化目标主机地址
	void destHostInit(int port, const char* ip);
	//接受数据线程
	static DWORD WINAPI RecvThread(LPVOID lparam);

	//监听套接字
	SOCKET m_listenSocket;
	//发送套接字
	SOCKET m_sendSocket;
	//目标主机地址
	SOCKADDR_IN m_destHost;

public:
	//发送端套接字是否创建(广播)
	bool m_bSendSocketInitBroad;
	//发送端套接字是否创建(指定)
	bool m_bSendSocketInitSpecial;
};

