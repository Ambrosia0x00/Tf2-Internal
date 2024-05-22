#pragma once
#ifndef MODULE_HPP
#define MODULE_HPP

#include"defines/crt.hpp"
#include"defines/winsdk.hpp"
#include"defines/xorstr.hpp"

class Module
{
private:
	uintptr_t module_base;
	unsigned long module_size;
public:
	Module(void) = default;
	Module(const wchar_t* sz_image);
public:
	void InitFromName(const wchar_t* sz_image);
	uintptr_t GetModuleBase() const;
public:
	inline PEB* GetProcessEnvBlock(unsigned long offset);
};

Module::Module(const wchar_t* sz_image)
{
	this->InitFromName(sz_image);
}

inline void Module::InitFromName(const wchar_t* sz_image)
{
	this->module_base = GetImage<uintptr_t>(sz_image);
}

inline uintptr_t Module::GetModuleBase() const
{
	return this->module_base;
}

inline PEB* Module::GetProcessEnvBlock(unsigned long offset)
{
	return reinterpret_cast<PEB*>(__readgsqword(offset));
}

#endif