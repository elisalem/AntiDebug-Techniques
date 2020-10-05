#include "FindMyProcess.h"

void FindMyProcess::FindMyProcessTwo(char proctofind[])
{

	
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry) == TRUE)
	{
		while (Process32Next(snapshot, &entry) == TRUE)
		{
			
			if (strcmp(proctofind, entry.szExeFile) == 0)
			{
				MessageBoxA(0, "I dont like this process :-)", "My Message Box", MB_OK);
				ExitProcess(0);
			}

			

			
		}


	}

}



FindMyProcess::FindMyProcess()
{
}


FindMyProcess::~FindMyProcess()
{
}
