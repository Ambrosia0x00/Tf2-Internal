#pragma once
#ifndef WIN32_HPP
#define WIN32_HPP

#include"mapdata/mapdata.hpp"
class Win32
{
public:
#pragma function(memcpy)
	void* memcpy(void* dest, const void* src, size_t size)
	{
		auto data_dest = static_cast<uint8_t*>(dest);
		auto data_src = static_cast<const uint8_t*>(src);
		__movsb(data_dest, data_src, size);
		return static_cast<void*>(data_dest);
	}
#pragma function(memset)
	void* memset(void* dest, int value, size_t size)
	{
		auto data_dest = static_cast<uint8_t*>(dest);
		__stosb(data_dest, static_cast<uint8_t>(value), size);
		return static_cast<void*>(data_dest);
	}
public:
	BOOL __stdcall MyRtlVirtualProtect(LPVOID lpVoid, SIZE_T lpSize, DWORD lpOld, PDWORD lpNew)
	{
		return pCall->Safecall_t<BOOL>((uintptr_t)mapdata.RtlVirtualProtect,
			lpVoid, lpSize, lpOld, lpNew);
	}
public:
	BOOL __stdcall MyRtlCloseHandle(HANDLE handle)
	{
		return pCall->Safecall_t<BOOL>((uintptr_t)mapdata.RtlCloseHandle, handle);
	}
	HANDLE __stdcall MyRtlCreateThread(LPTHREAD_START_ROUTINE routine, LPVOID buffer, LPDWORD thread)
	{
		return pCall->Safecall_t<HANDLE>((uintptr_t)mapdata.RtlCreateThread,
			NULL, NULL, routine, buffer, NULL, thread);
	}
}; inline Win32* pWin32;

#endif