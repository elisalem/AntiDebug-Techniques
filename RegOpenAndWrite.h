#pragma once
#include "CreateMyFile.h"

class RegOpenAndWrite
{

private:

	HKEY _regHandleKey;

public:
	LPCSTR _regpath;

	RegOpenAndWrite();

	void RegOpenAndWriteTwo(LPCSTR _regpath, string regcontent);




	~RegOpenAndWrite();
};

