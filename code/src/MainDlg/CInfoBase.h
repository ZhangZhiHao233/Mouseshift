/*****************************************************
 Author: ��־��
 Mail: 791745123@qq.com
 Time: 2019-1-5
 Function:
	���Ļ���
 Version: v 1.0
*****************************************************/
#pragma once
#include "commonType.h"
#include <memory>

#define BUFF_LENGTH 128

class CInfoBase
{
public:
	CInfoBase():infoType(0), senderType(0)
	{
		memset(addMsg, 0, BUFF_LENGTH);
	}

	bool InputAddMsg(const char* buff, int length)
	{
		if (length < BUFF_LENGTH && length > 0)
		{
			memcpy(addMsg, buff, length);
			return true;
		}

		return false;
	}
public:
	//��Ϣ����
	int infoType;
	//������
	int senderType;
	//������Ϣ
	char addMsg[BUFF_LENGTH];
};