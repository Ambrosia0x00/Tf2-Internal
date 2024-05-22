#pragma once
#ifndef SAFECALL_HPP
#define SAFECALL_HPP

using qword = unsigned long long;
class Safecall
{
public:
	template<typename ReturnType, typename... Args>
	ReturnType Call(qword address, Args... args);

	template<typename ReturnType, typename... Args>
	ReturnType Safecall_t(qword address, Args... args);
}; inline Safecall* pCall;

template<typename ReturnType, typename... Args>
inline ReturnType Safecall::Call(qword address, Args... args)
{
	using Fn = ReturnType(*)(Args...);
	auto addr = reinterpret_cast<Fn>(address);
	return addr(args...);
}

template<typename ReturnType, typename... Args>
inline ReturnType Safecall::Safecall_t(qword address, Args... args)
{
	return Call<ReturnType, Args...>(address, args...);
}

#endif