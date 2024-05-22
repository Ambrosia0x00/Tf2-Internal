#pragma once
#ifndef CAPTURE_HPP
#define CAPTURE_HPP

#include"../win32/win32.hpp"

class Capture
{
public:
	template<typename Interface_t>
	Interface_t CaptureInterface(const wchar_t* sz_image, const char* sz_interface);
}; inline Capture* pCapture;

template<typename Interface_t>
inline Interface_t Capture::CaptureInterface(const wchar_t* sz_image, const char* sz_interface)
{
	const auto h_module = GetImage<uintptr_t>(sz_image);
	if (h_module == 0)
		return nullptr;
	const auto h_function = reinterpret_cast<void* (__cdecl*)(const char*,
		int*)>(GetImageExport(h_module, "CreateInterface"));
	if (h_function == 0)
		return nullptr;
	return reinterpret_cast<Interface_t>(h_function(sz_interface, nullptr));
}

#endif