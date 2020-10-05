#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS


using namespace std;


#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#pragma comment(lib, "WINMM.LIB")

#include <string.h>
#include <winsock2.h>

#include <iostream>
#include <vector>
#include <locale>
#include <sstream>




#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "80"


#include "CreateMyFile.h"
#include "WriteMyFile.h"
#include "RegOpenAndWrite.h"
#include "FindMyWindow.h"
#include "FindMyProcess.h"
#include "Network.h"
#include "TimeChecks.h"
#include "MemoryAntiDebug.h"


int __cdecl main(int argc, char** argv)
{
	/*
	Author: Eli Salem
	This program was created for research & educational purposes
	*/

	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////// Initial information about the machine ///////////////////
	///////////////////////////////////////////////////////////////////////////////////


	TCHAR computerName[100];
	DWORD size3 = 100;
	GetComputerName(computerName, &size3);

	char username[10];
	DWORD username_len = 10;
	GetUserName(username, &username_len);

	DWORD majorVersion = NULL;
	OSVERSIONINFOEX osVersionInfo;
	::ZeroMemory(&osVersionInfo, sizeof(OSVERSIONINFOEX));
	osVersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	osVersionInfo.dwMajorVersion = majorVersion;

	
	FindMyWindow fw;
	FindMyProcess fp;
	



	BOOL debug;

	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////// Finding existance of processes //////////////////////////
	///////////////////////////////////////////////////////////////////////////////////


	char vms[13];  // vmtools stack strings
	char phk[18];  // process hacker stack strings
	vms[0] = { 'v' };
	vms[1] = { 'm' };
	vms[2] = { 't' };
	vms[3] = { 'o' };
	vms[4] = { 'o' };
	vms[5] = { 'l' };
	vms[6] = { 's' };
	vms[7] = { 'd' };
	vms[8] = { '.' };
	vms[9] = { 'e' };
	vms[10] = { 'x' };
	vms[11] = { 'e' };
	vms[12] = { '\0' };

	phk[0] = { 'P' };
	phk[1] = { 'r' };
	phk[2] = { 'o' };
	phk[3] = { 'c' };
	phk[4] = { 'e' };
	phk[5] = { 's' };
	phk[6] = { 's' };
	phk[7] = { 'H' };
	phk[8] = { 'a' };
	phk[9] = { 'c' };
	phk[10] = { 'k' };
	phk[11] = { 'e' };
	phk[12] = { 'r' };
	phk[13] = { '.' };
	phk[14] = { 'e' };
	phk[15] = { 'x' };
	phk[16] = { 'e' };
	phk[17] = { '\0' };
	

	
	char ph[] = "Procmon.exe";
	char ps[] = "pestudio.exe";
	char pe[] = "procexp64.exe";

	fp.FindMyProcessTwo(phk);
	fp.FindMyProcessTwo(vms);
	fp.FindMyProcessTwo(ph);
	fp.FindMyProcessTwo(ps);
	fp.FindMyProcessTwo(pe);

	///////////////////////////////////////////////////////////////////////////////////
	/////////////////////////// Finding wireshark window //////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////


	int isWindow;
	isWindow = fw.FindMyWindowTwo("Wireshark");
	if (isWindow == 1)
	{
		MessageBoxA(0, "I dont like this program :-)", "My Message Box", MB_OK);

		ExitProcess(0);
	}

	debug = IsDebuggerPresent();
	if (debug != 0) {

		MessageBoxA(0, "I know im running in a context of a debugger :-)", "My Message Box", MB_OK);
		ExitProcess(0);

	}



	
	///////////////////////////////////////////////////////////////////////////////////
	/////////////////////////// Testing  origin of machine ////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////


	int x = GetSystemDefaultLCID();
	if (x != 1037) {
		MessageBoxA(0, "Wrong Country :-)", "My Message Box", MB_OK);
		ExitProcess(0);
	}


    ////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////// Testing network activity //////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////
	Network nt;
	string netstr;
	string netstr2;
	netstr = nt.MyNetwork("www.google.com");
	netstr2 = netstr.substr(0, 4);
	if (netstr2._Equal("HTTP") == FALSE) {
		MessageBoxA(0, "Your internet is offline :-)", "My Message Box", MB_OK);

		ExitProcess(0);


	}


	//////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////// XOR encryption and decryption ///////////////////////////
	////////////////////////////////////////////////////////////////////////////////////
	
	int key4 = 22;



	int data_len = 19;
	int data_len2 = 34;

	int key = 22;

	

	char sec44[] = "B~s6Fweeaydr6_e,6Fy}s{yn";

	char sec3[] = "U,JCesdeJFctzuJFweeaydrPzs8bnb\x16";




	for (int i = 0; i < 23; i++)
	{
		sec44[i] ^= key;
	}

	for (int i = 0; i < data_len2; i++)
	{
		sec3[i] ^= key;
	}

	/////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////// Time checks anti debug  ///////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////

	TimeChecks tc;
	tc.adbg_GetTickCount();
	tc.adbg_QueryPerformanceCounter();
	tc.adbg_RDTSC();

	/////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////// Memory anti debug  ////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////

	MemoryAntiDebug mad;
	mad.adbg_BeingDebuggedPEB();
	mad.adbg_CheckRemoteDebuggerPresent();
	mad.adbg_IsDebuggerPresent();
	mad.adbg_NtGlobalFlagPEB();
	mad.adbg_NtQueryInformationProcess_debugPort();
	mad.adbg_NtSetInformationThread();
	mad.MemoryBreakpoint();

	/////////////////////////////////////////////////////////////////////////////////////
	//////////////// Creating file, Write Content & write to registry  //////////////////
	/////////////////////////////////////////////////////////////////////////////////////
	
	CreateMyFile fc;
	WriteMyFile mf;
	HANDLE fileHandle;
	RegOpenAndWrite regactivity;


	fileHandle = fc.CreateMyFileTwo(sec3);

	mf.WriteMyFileTwo(sec44, fileHandle);

	LPCSTR registryEntry = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
	regactivity.RegOpenAndWriteTwo(registryEntry, sec3);
	
	CloseHandle(fileHandle);

	


	


	

	return 0;
};