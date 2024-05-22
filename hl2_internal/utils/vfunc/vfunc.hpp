#pragma once
#ifndef VFUNC_HPP
#define VFUNC_HPP

class VFunc
{
public:
	template<typename ReturnType, typename... Args>
	ReturnType CallVFunc(int index, void* this_ptr, Args... args);
public:
	uintptr_t GetVPtr(void* base, int index);
}; inline VFunc* pFunc;

template<typename ReturnType, typename... Args>
inline ReturnType VFunc::CallVFunc(int index, void* this_ptr, Args... args)
{
	return (*reinterpret_cast<ReturnType(__fastcall***)(void*, Args...)>(this_ptr))[index](this_ptr, args...);
}

#endif