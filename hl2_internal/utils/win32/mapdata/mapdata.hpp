#pragma once
#ifndef MAPDATA_HPP
#define MAPDATA_HPP

#include"../module/module.hpp"
#include"../safecall/safecall.hpp"

class Mapdata
{
public:
	typedef HANDLE(__stdcall* _RtlCreateThread)(LPSECURITY_ATTRIBUTES,
		SIZE_T, LPTHREAD_START_ROUTINE, LPVOID, DWORD, LPDWORD);
	_RtlCreateThread RtlCreateThread = nullptr;

	typedef BOOL(__stdcall* _RtlCloseHandle)(HANDLE);
	_RtlCloseHandle RtlCloseHandle = nullptr;

	typedef BOOL(__stdcall* _RtlDisableThreads)(HMODULE);
	_RtlDisableThreads RtlDisableThreads = nullptr;
public:
	typedef BOOL(__stdcall* _RtlVirtualProtect)(LPVOID, SIZE_T, DWORD, PDWORD);
	_RtlVirtualProtect RtlVirtualProtect = nullptr;
public:
	bool Initialize(const wchar_t* ntdll,
		const wchar_t*kernel, const wchar_t* user);
}; inline Mapdata mapdata;

inline bool Mapdata::Initialize(const wchar_t* ntdll,
	const wchar_t* kernel, const wchar_t* user)
{
	Module ntdll_image(ntdll);
	Module kernel_image(kernel);
	Module user_image(user);

	if (ntdll_image.GetModuleBase() == 0 || kernel_image.GetModuleBase() == 0)
		return false;


	RtlVirtualProtect = (_RtlVirtualProtect)(GetImageExport(kernel_image.GetModuleBase(),
		xorstr_("VirtualProtect")));
	RtlCreateThread = (_RtlCreateThread)(GetImageExport(kernel_image.GetModuleBase()
		, xorstr_("CreateThread")));
	RtlCloseHandle = (_RtlCloseHandle)(GetImageExport(kernel_image.GetModuleBase(),
		xorstr_("CloseHandle")));
	RtlDisableThreads = (_RtlDisableThreads)(GetImageExport(kernel_image.GetModuleBase(),
		xorstr_("DisableThreadLibraryCalls")));

	return true;
}

#endif