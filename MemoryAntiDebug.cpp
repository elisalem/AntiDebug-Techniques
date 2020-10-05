#include "MemoryAntiDebug.h"



MemoryAntiDebug::MemoryAntiDebug()
{
}


MemoryAntiDebug::~MemoryAntiDebug()
{
}

void MemoryAntiDebug::adbg_BeingDebuggedPEB(void)
{
	BOOL found = FALSE;
	_asm
	{
		xor eax, eax;			// clear eax
		mov eax, fs: [0x30] ;		// Reference start of the PEB
		mov eax, [eax + 0x02];	// PEB+2 points to BeingDebugged
		and eax, 0x000000FF;	// only reference one byte
		mov found, eax;			// Copy BeingDebugged into 'found'
	}

	if (found)
	{
		MessageBoxA(0, "I'm being debugged :-)", "My Message Box", MB_OK);

		ExitProcess(0);
	}
}


void MemoryAntiDebug::adbg_CheckRemoteDebuggerPresent(void)
{
	HANDLE hProcess = INVALID_HANDLE_VALUE;
	BOOL found = FALSE;

	hProcess = GetCurrentProcess();
	CheckRemoteDebuggerPresent(hProcess, &found);

	if (found)
	{
		MessageBoxA(0, "Remote Debugger is present :-)", "My Message Box", MB_OK);

		ExitProcess(0);
	}
}

void MemoryAntiDebug::adbg_IsDebuggerPresent(void)
{
	BOOL found = FALSE;
	found = IsDebuggerPresent();

	if (found)
	{
		MessageBoxA(0, "Debugger is present :-)", "My Message Box", MB_OK);

		ExitProcess(0);
	}
}

void MemoryAntiDebug::adbg_NtGlobalFlagPEB(void)
{
	BOOL found = FALSE;
	_asm
	{
		xor eax, eax;			// clear eax
		mov eax, fs: [0x30] ;		// Reference start of the PEB
		mov eax, [eax + 0x68];	// PEB+0x68 points to NtGlobalFlags
		and eax, 0x00000070;	// check three flags
		mov found, eax;			// Copy result into 'found'
	}

	if (found)
	{
		MessageBoxA(0, "Debugger is present :-)", "My Message Box", MB_OK);

		ExitProcess(0);
	}
}

void MemoryAntiDebug::adbg_NtQueryInformationProcess_debugPort(void)
{
	HANDLE hProcess = INVALID_HANDLE_VALUE;
	DWORD found = FALSE;
	DWORD ProcessDebugPort = 0x07;	// 1st method; See MSDN for details
	DWORD ProcessDebugFlags = 0x1F;	// 2nd method; See MSDN for details

	// Get a handle to ntdll.dll so we can import NtQueryInformationProcess
	HMODULE hNtdll = LoadLibraryW(L"ntdll.dll");
	if (hNtdll == INVALID_HANDLE_VALUE || hNtdll == NULL)
	{
		_asm
		{
			nop;
		}
	}

	// Dynamically acquire the addres of NtQueryInformationProcess
	_NtQueryInformationProcess NtQueryInformationProcess = NULL;
	NtQueryInformationProcess = (_NtQueryInformationProcess)GetProcAddress(hNtdll, "NtQueryInformationProcess");

	if (NtQueryInformationProcess == NULL)
	{
		_asm
		{
			nop;
		}
	}

	// Method 1: Query ProcessDebugPort
	hProcess = GetCurrentProcess();
	NTSTATUS status = NtQueryInformationProcess(hProcess, ProcessDebugPort, &found, sizeof(DWORD), NULL);

	if (!status && found)
	{
		MessageBoxA(0, "Debugger is present :-)", "My Message Box", MB_OK);

		ExitProcess(0);
		exit(0x1004);
	}


}

void MemoryAntiDebug::adbg_NtSetInformationThread(void)
{
	DWORD ThreadHideFromDebugger = 0x11;

	// Get a handle to ntdll.dll so we can import NtSetInformationThread
	HMODULE hNtdll = LoadLibraryW(L"ntdll.dll");
	if (hNtdll == INVALID_HANDLE_VALUE || hNtdll == NULL)
	{

	
		_asm
		{
			nop;
		}
	}

	// Dynamically acquire the addres of NtSetInformationThread and NtQueryInformationThread
	_NtSetInformationThread NtSetInformationThread = NULL;
	NtSetInformationThread = (_NtSetInformationThread)GetProcAddress(hNtdll, "NtSetInformationThread");

	if (NtSetInformationThread == NULL)
	{

	
		_asm
		{
			nop;
		}
	}

	// There is nothing to check here after this call.
	NtSetInformationThread(GetCurrentThread(), THREAD_INFORMATION_CLASS(ThreadHideFromDebugger), 0, 0);


}

void MemoryAntiDebug::MemoryBreakpoint(void) {


	MessageBoxA(0, "Please set memory breakpoint on VirtuallAlloc :-)", "My Message Box", MB_OK);


	bool breakPointPresent = false;
	unsigned char* memPtr = reinterpret_cast<unsigned char*>(VirtualAlloc(NULL, 3000, MEM_RESERVE, PAGE_READWRITE));

	auto size = 0x16; //this value determined by manual inspection of compiled code

	for (size_t i = 0; i < size; i++) {
		if (memPtr[i] == 0xCC) {           //see if byte equals int 3 instruction
			breakPointPresent = true;
			MessageBoxA(0, "Debugger is present :-)", "My Message Box", MB_OK);
			break;
		}
	}
}