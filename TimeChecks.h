#pragma once
#include "CreateMyFile.h"

class TimeChecks
{
public:
	TimeChecks();
	~TimeChecks();


	void adbg_RDTSC(void);
	void adbg_QueryPerformanceCounter(void);
	void adbg_GetTickCount(void);
};

