#pragma once
#include "CreateMyFile.h"



class WriteMyFile
{

private:
	DWORD _dwBytesToWrite; 
	DWORD _dwBytesWritten = 0;
	BOOL _bErrorFlag = FALSE;


public:
	char _fileBuffer[];

	void setBytesToWrite(DWORD _dwBytesToWrite) {
		this->_dwBytesToWrite = _dwBytesToWrite;
	}

WriteMyFile();

void WriteMyFileTwo(char _fileBuffer[], HANDLE _handleToFile);



virtual ~WriteMyFile();
};

