#include "TimeChecks.h"



TimeChecks::TimeChecks()
{
}


TimeChecks::~TimeChecks()
{
}


void TimeChecks::adbg_RDTSC(void)
{
	BOOL found = FALSE;

	UINT64 timeA, timeB = 0;
	int timeUpperA, timeLowerA = 0;
	int timeUpperB, timeLowerB = 0;

	_asm
	{

		// rdtsc stores result across EDX:EAX

		// first time calculation
		rdtsc; 
		mov timeUpperA, edx;
		mov timeLowerA, eax;

		// some junk

		xor eax, eax;
		mov eax, 5;
		shr eax, 2;
		sub eax, ebx;
		cmp eax, ecx
		
		// second time calculation
		rdtsc; 
		mov timeUpperB, edx;
		mov timeLowerB, eax;
	}

	timeA = timeUpperA;
	timeA = (timeA << 32) | timeLowerA;

	timeB = timeUpperB;
	timeB = (timeB << 32) | timeLowerB;

	// comprasion to the threshold
	if (timeB - timeA > 0x10000)
	{
		found = TRUE;
	}

	if (found)
	{
		MessageBoxA(0, "Remote Debugger is present :-)", "My Message Box", MB_OK);

		ExitProcess(0);
	}
}

void TimeChecks::adbg_QueryPerformanceCounter(void)
{
	BOOL found = FALSE;
	LARGE_INTEGER t1;
	LARGE_INTEGER t2;

	// first time count
	QueryPerformanceCounter(&t1);

	// some junk
	int x = 20;
	int y = 20;
	int z = x + y;

	// second time count
	QueryPerformanceCounter(&t2);

	//compression,  30 is an empirical value
	if ((t2.QuadPart - t1.QuadPart) > 30)
	{
		found = TRUE;
	}

	if (found)
	{
		MessageBoxA(0, "Remote Debugger is present :-)", "My Message Box", MB_OK);

		ExitProcess(0);
	}
}


void TimeChecks::adbg_GetTickCount(void)
{
	BOOL found = FALSE;
	DWORD t1;
	DWORD t2;

	// first time count
	t1 = GetTickCount64();

	// some junk
	int x = 20;
	int y = 20;
	int z = x + y;

	// second time count
	t2 = GetTickCount64();

	//compression, 30 milliseconds is an empirical value
	if ((t2 - t1) > 30)
	{
		found = TRUE;
	}

	if (found)
	{
		MessageBoxA(0, "Remote Debugger is present :-)", "My Message Box", MB_OK);

		ExitProcess(0);
	}
}