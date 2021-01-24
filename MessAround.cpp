#ifdef _MSC_VER
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#endif

#include <stdio.h>
#include <Windows.h>
#include <iostream>
using namespace std;

int main()
{
	bool pauseFlag = true;
	bool winFrontState = true;
	bool firstInit = true;
	int posLeft, posTop, width, height;
	RECT rectpos;
	HWND handle = FindWindow(NULL, "���л�");
	if (handle)
	{
		GetWindowRect(handle, &rectpos);

		posLeft = rectpos.left;
		posTop = rectpos.top;
		width = rectpos.right - rectpos.left;
		height = rectpos.bottom - rectpos.top;
		// cout << rectpos.left << "  " <<  rectpos.top << "  " << rectpos.right - rectpos.left << "  " << rectpos.bottom - rectpos.top << endl;

		MessageBox(NULL, "���������У���ס��Shift�����ţ��ɿ���Shift���ش��ڲ���ͣ��\n�ر����������������", "��ʾ", 0);

		while (true)
		{
			if (GetAsyncKeyState(VK_RSHIFT) && 0x8000)
			{
				if (!pauseFlag)
				{
					if(!firstInit && winFrontState)
					{
						SetForegroundWindow(handle);
						PostMessage(handle, WM_KEYDOWN, VK_SPACE, 0);
						pauseFlag = true;
						SetWindowPos(handle, HWND_TOPMOST, posLeft, posTop, width, height, SWP_SHOWWINDOW);
						winFrontState = false;
					}
					else 
					{
						firstInit = false;
					}
				}
			}
			else
			{
				if (pauseFlag)
				{
					SetForegroundWindow(handle);
					PostMessage(handle, WM_KEYDOWN, VK_SPACE, 0);
					SetWindowPos(handle, HWND_TOPMOST, posLeft, posTop, width, height, SWP_HIDEWINDOW);
					pauseFlag = false;
					winFrontState = true;
				}
			}
		}
	}
	else
	{
		MessageBox(NULL, "δ���ֻ��л����ھ��", "��ʾ", 0);
		return 0;
	}

	return 0;
}