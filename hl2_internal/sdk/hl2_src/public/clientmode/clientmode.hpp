#pragma once
#ifndef CLIENTMODE_HPP
#define CLIENTMODE_HPP

#include"../../utils/vfunc/vfunc.hpp"
class ClientMode_t
{
public:
	void Printf(const int ifliter, const char* fmt, ...)
	{
		int index = 18;
		pFunc->CallVFunc<void>(index, this, ifliter, fmt);
	}
	void ChatPrintf(const int iplayer, const char* ifliter, const char* fmt, ...)
	{
		int index = 19;
		pFunc->CallVFunc<void>(index, this, iplayer, ifliter, fmt);
	}
};

#endif