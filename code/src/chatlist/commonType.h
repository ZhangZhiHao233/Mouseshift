/*****************************************************
 Author: 张志浩
 Mail: 791745123@qq.com
 Time: 2019-1-5
 Function:
	通用变量、宏定义头文件
		DESTPORT : 目标主机端口
		SENDERTYPE : 发送者类型
		MSGTYPE ： 消息类型
 Version: v 1.0
*****************************************************/

#pragma once

typedef enum
{
	PORT_MAINDLG = 8000,
	PORT_COMPASS,
	PORT_CHATLIST
}DESTPORT;

typedef enum
{
	PROCESS_NONE = 100,
	PROCESS_MAINDLG,
	PROCESS_COMPASS,
	PROCESS_CHATLIST
}SENDERTYPE;

typedef enum
{
	MSG_NONE = 10,
	MSG_CHANGEMOUSEPOS
}MSGTYPE;
