#include <windows.h>
#include <stdio.h>
#include <iostream>



void Hack()
{
	if (GetAsyncKeyState(VK_F1) & 1) // Increase Ammo by 100
	{

		DWORD ammos =
		{
			*(DWORD*)(
			*(DWORD*)((int)GetModuleHandle(L"ac_client.exe") + 0x00109B74)
			+ 0x150)
		};

		DWORD hexammos = ammos + 100;
	*(DWORD*)(
	*(DWORD*)((int)GetModuleHandle(L"ac_client.exe") + 0x00109B74)
	+ 0x150) = hexammos;
	}
	if (GetAsyncKeyState(VK_F2) & 1) // Ammo doubled
	{

		DWORD ammos =
		{
			*(DWORD*)(
			*(DWORD*)((int)GetModuleHandle(L"ac_client.exe") + 0x00109B74)
			+ 0x150)
		};

		DWORD hexammos = ammos + ammos;
		*(DWORD*)(
			*(DWORD*)((int)GetModuleHandle(L"ac_client.exe") + 0x00109B74)
			+ 0x150) = hexammos;
	}
}

void MainThread()
{
	while (true) // you can use 1/0/NULL or true/false
	{
		Hack();
		Sleep(1);
	}
}