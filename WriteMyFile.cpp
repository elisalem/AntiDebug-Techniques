#include "WriteMyFile.h"

void WriteMyFile::WriteMyFileTwo(char buff[], HANDLE _handleToFile)
{
	this->_dwBytesToWrite = (DWORD)strlen(buff);
	
	
	_bErrorFlag = WriteFile(_handleToFile, buff, _dwBytesToWrite, &_dwBytesWritten, NULL);


	// Checking if the writing to the file has succeeded
	if (_bErrorFlag == FALSE)
	{
		cout << "WRITING TO FILE FAILED";
		
	}
	else
	{
		cout << "WRITING TO FILE SUCCEED";
	}
	CloseHandle(_handleToFile);

}


WriteMyFile::WriteMyFile()
{
}


WriteMyFile::~WriteMyFile()
{
}
