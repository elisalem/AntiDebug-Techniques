#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "CreateMyFile.h"

class Network
{
public:

	WSADATA wsaData;
	SOCKET Socket;
	SOCKADDR_IN SockAddr;
	int lineCount = 0;
	int rowCount = 0;
	struct hostent* host;
	locale local;
	char buffer[10000];
	int i = 0;
	int nDataLength;
	string website_HTML;
	string url = "www.google.com";

	string smth;




	Network();
	string MyNetwork(string url);
	virtual ~Network();
};

