#include "CreateMyFile.h"



CreateMyFile::CreateMyFile()
{
}

HANDLE CreateMyFile::CreateMyFileTwo(LPCSTR path) {
	setpath();
	
	_hFile = CreateFile(path, GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL); // FILE CREATION

	if (_hFile == INVALID_HANDLE_VALUE) // TESTING IF FILE CREATION SUCCEED
	{
		cout << "file creation failed";
		
	}

	return _hFile;


}
CreateMyFile::~CreateMyFile()
{
}
