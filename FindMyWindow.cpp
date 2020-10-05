#include "FindMyWindow.h"

int FindMyWindow::FindMyWindowTwo(LPCSTR wn)
{
	HWND Find;

	Find = ::FindWindowEx(0, 0, wn, 0);
	if (Find == NULL)
	{
		cout << "findwindow failed";
		return 0;
	}
	else
	{
		cout << " findwindow success";
		return 1;
	}
}



FindMyWindow::FindMyWindow()
{
}


FindMyWindow::~FindMyWindow()
{
}
