#ifdef _MSC_VER
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#endif

#include <stdio.h>
#include <Windows.h>
#include <iostream>
using namespace std;

int main()
{
	bool flag = true;
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

		MessageBox(NULL, "���������У���סCtrl�����ţ��ɿ�Ctrl���ش��ڲ���ͣ��\n�ر����������������", "��ʾ", 0);

		while (true)
		{
			if (GetAsyncKeyState(VK_CONTROL) && 0x8000)
			{
				if (!flag)
				{
					if(!firstInit)
					{
						SetForegroundWindow(handle);
						PostMessage(handle, WM_KEYDOWN, VK_SPACE, 0);
						flag = true;
					}
					else 
					{
						firstInit = false;
					}
				}
				SetWindowPos(handle, HWND_NOTOPMOST, posLeft, posTop, width, height, SWP_SHOWWINDOW);
			}
			else
			{
				if (flag)
				{
					SetForegroundWindow(handle);
					PostMessage(handle, WM_KEYDOWN, VK_SPACE, 0);
					SetWindowPos(handle, HWND_TOPMOST, posLeft, posTop, width, height, SWP_HIDEWINDOW);
					flag = false;
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