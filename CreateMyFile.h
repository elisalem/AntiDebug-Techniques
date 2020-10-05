#pragma once
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <strsafe.h>
#include <tchar.h>
#include <iostream>
#include <mmsystem.h>
#include <filesystem>
#include <conio.h>
#include <TlHelp32.h>
#include <string.h>
#include <winsock2.h>
using namespace std;


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
class CreateMyFile
{

private:
	HANDLE _hFile;




public:
	LPCSTR path;

	void setpath() {
		this->path = path;
	}
	LPCSTR getpath() {
		return this->path;
	}

CreateMyFile();
HANDLE CreateMyFileTwo(LPCSTR path);




virtual ~CreateMyFile();
};

