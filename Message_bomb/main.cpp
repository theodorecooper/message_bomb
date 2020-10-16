#define _CRT_SECURE_NO_DEPRECATE 

#include <stdio.h>
#include <stdlib.h>
#include <atlstr.h>
#include <string>
#include <windows.h>

char str[256];

void click() //鼠标控制函数
{
	SetCursorPos(803, 687); //将鼠标定向到窗口
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0); //左键按下
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);  //左键松开
}

int setClipbar(const char *data)
{
	HGLOBAL hMemory; 
	LPTSTR lpMemory;
	if (!OpenClipboard(NULL))
		return 0;
	/* 打开剪切板 */
	if (!EmptyClipboard()) 
		return 0; 
	/* 清空剪切板 */
	if (!(hMemory = GlobalAlloc(GMEM_MOVEABLE, strlen(data) + 1)))
		return 0;
	/* 对剪切板分配内存 */
	if (!(lpMemory = (LPTSTR)GlobalLock(hMemory))) 
		return 0;
	/* 锁定内存区域 */
	memcpy_s(lpMemory, strlen(data) + 1, data, strlen(data) + 1);
	/* 复制数据到内存区域 */
	GlobalUnlock(hMemory);                                
	/* 解除内存锁定 */
	if (!SetClipboardData(CF_TEXT, hMemory)) 
		return 0;      
	/* 设置剪切板数据 */
	printf("成功复制[%s]到剪切板，字符串长度为%d。\n", data, strlen(data) + 1);
	CloseClipboard();
	/* 关闭剪切板 */
	return 1;
}

int main(char argc, char* argv[])
{
	
	printf("1.Edit and send strings.\n");
	scanf("%s", &str);

	setClipbar(str);
	system("color 0A");
	SetWindowPos(GetConsoleWindow(), HWND_TOPMOST, 0, 0, 200, 200, SWP_SHOWWINDOW); //设置窗口，重要一步
	Sleep(100);
	printf("  \n");
	printf("  \n");
	printf("  \n");
	printf(" press SHIFT to stop \n");
	printf(" 键入SHIFT停止发送 \n");
	Sleep(10);

	int a;
	while (1)
	{
		a = GetKeyState(VK_SHIFT);
		if (a < 0)
		{
			break;
		}


		Sleep(10);
		//click();
		Sleep(10); //休眠

		keybd_event(0x11, 0, 0, 0);
		keybd_event(0x56, 0, 0, 0);
		keybd_event(0x56, 0, 2, 0);
		keybd_event(0x11, 0, 2, 0);
		keybd_event(0x0D, 0, 0, 0);
		keybd_event(0x0D, 0, 2, 0);
		Sleep(40); //休眠

		Sleep(50); //休眠
	}
	return 0;
}