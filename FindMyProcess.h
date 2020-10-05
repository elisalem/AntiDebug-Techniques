#pragma once
#include "CreateMyFile.h"
class FindMyProcess
{
public:
	
	PROCESSENTRY32 entry;
	
	void FindMyProcessTwo(char proctofind[]);




	FindMyProcess();
	virtual ~FindMyProcess();
};

