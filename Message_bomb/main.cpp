#define _CRT_SECURE_NO_DEPRECATE 

#include <stdio.h>
#include <stdlib.h>
#include <atlstr.h>
#include <string>
#include <windows.h>

char str[256];

void click() //�����ƺ���
{
	SetCursorPos(803, 687); //����궨�򵽴���
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0); //�������
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);  //����ɿ�
}

int setClipbar(const char *data)
{
	HGLOBAL hMemory; 
	LPTSTR lpMemory;
	if (!OpenClipboard(NULL))
		return 0;
	/* �򿪼��а� */
	if (!EmptyClipboard()) 
		return 0; 
	/* ��ռ��а� */
	if (!(hMemory = GlobalAlloc(GMEM_MOVEABLE, strlen(data) + 1)))
		return 0;
	/* �Լ��а�����ڴ� */
	if (!(lpMemory = (LPTSTR)GlobalLock(hMemory))) 
		return 0;
	/* �����ڴ����� */
	memcpy_s(lpMemory, strlen(data) + 1, data, strlen(data) + 1);
	/* �������ݵ��ڴ����� */
	GlobalUnlock(hMemory);                                
	/* ����ڴ����� */
	if (!SetClipboardData(CF_TEXT, hMemory)) 
		return 0;      
	/* ���ü��а����� */
	printf("�ɹ�����[%s]�����а壬�ַ�������Ϊ%d��\n", data, strlen(data) + 1);
	CloseClipboard();
	/* �رռ��а� */
	return 1;
}

int main(char argc, char* argv[])
{
	
	printf("1.Edit and send strings.\n");
	scanf("%s", &str);

	setClipbar(str);
	system("color 0A");
	SetWindowPos(GetConsoleWindow(), HWND_TOPMOST, 0, 0, 200, 200, SWP_SHOWWINDOW); //���ô��ڣ���Ҫһ��
	Sleep(100);
	printf("  \n");
	printf("  \n");
	printf("  \n");
	printf(" press SHIFT to stop \n");
	printf(" ����SHIFTֹͣ���� \n");
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
		Sleep(10); //����

		keybd_event(0x11, 0, 0, 0);
		keybd_event(0x56, 0, 0, 0);
		keybd_event(0x56, 0, 2, 0);
		keybd_event(0x11, 0, 2, 0);
		keybd_event(0x0D, 0, 0, 0);
		keybd_event(0x0D, 0, 2, 0);
		Sleep(40); //����

		Sleep(50); //����
	}
	return 0;
}