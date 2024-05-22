#pragma once
#ifndef HOOKER_HPP
#define HOOKER_HPP

#include<memory>
#include"../win32/win32.hpp"
#include"minhook/include/MinHook.h"

class Hook_t
{
public:
	uintptr_t vmt_hook(void* target, size_t size, uintptr_t detour);
}; inline Hook_t* pHook;

inline uintptr_t Hook_t::vmt_hook(void* target, size_t index, uintptr_t detour)
{
	uintptr_t table = *(uintptr_t*)(target);
	uintptr_t function_addr = table + index * sizeof(uintptr_t);
	uintptr_t original_addr = *(uintptr_t*)(function_addr);

	DWORD old_protect;
	pWin32->MyRtlVirtualProtect((LPVOID)function_addr, sizeof(uintptr_t), PAGE_EXECUTE_READWRITE, &old_protect);
	*(uintptr_t*)(function_addr) = (uintptr_t)detour;
	pWin32->MyRtlVirtualProtect((LPVOID)function_addr, sizeof(uintptr_t), old_protect, &old_protect);

	return original_addr;
}


#endif