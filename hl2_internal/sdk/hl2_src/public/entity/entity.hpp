#pragma once
#include"../../../netvar/netvar.hpp"

class BaseEntity_t
{
public:
	int m_iHealth()
	{
		int offset = pNetVar->GetNetVar("", "");
		return *reinterpret_cast<int*>(reinterpret_cast<unsigned long>(this) + offset);
	}
	int m_iTeamNum()
	{
		int offset = pNetVar->GetNetVar("", "");
		return *reinterpret_cast<int*>(reinterpret_cast<unsigned long>(this) + offset);
	}
};