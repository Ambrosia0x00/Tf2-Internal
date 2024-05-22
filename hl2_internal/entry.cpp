#pragma once
#include"sdk/sdk.hpp"
#include"utils/utils.hpp"
#include<thread>
#include<chrono>

bool __stdcall DllMain(uint8_t h_module, unsigned long call_reasons, void* call_buffer)
{
	if (call_reasons != 0x1)
		return false;
	
	AllocConsole();
	FILE* in = {};
	freopen_s(&in, "CONOUT$", "w", stdout);

	mapdata.Initialize(xorstr_(L"ntdll.dll"), xorstr_(L"kernel32.dll"), xorstr_(L"user32.dll"));
	pInterfaces->Initialize();
	pDetours->Initialize();

	return true;
}