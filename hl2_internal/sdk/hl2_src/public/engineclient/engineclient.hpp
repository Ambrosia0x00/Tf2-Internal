#pragma once
#ifndef ENGINECLIENT_HPP
#define ENGINECLIENT_HPP

#include"../../utils/vfunc/vfunc.hpp"

class EngineClient_t
{
public:
	void GetScreenSize(int& width_out, int& height_out)
	{
		return pFunc->CallVFunc<void>(5, this, width_out, height_out);
	}
	void ServerCmd(const char* string, bool null)
	{
		return pFunc->CallVFunc<void>(6, this, string, null);
	}
	bool GetPlayerInfo(int index, void* pPlayerInfo)
	{
		return pFunc->CallVFunc<bool>(8, this, index, pPlayerInfo);
	}
	int GetPlayerForUserId(int user)
	{
		return pFunc->CallVFunc<int>(9, this, user);
	}
	bool Con_IsVisible()
	{
		return pFunc->CallVFunc<bool>(11, this);
	}
	int GetLocalPlayer()
	{
		return pFunc->CallVFunc<int>(12, this);
	}
	float Time()
	{
		return pFunc->CallVFunc<float>(14, this);
	}
	int GetMaxClients()
	{
		return pFunc->CallVFunc<int>(21, this);
	}
	bool IsInGame()
	{
		return pFunc->CallVFunc<bool>(26, this);
	}
	bool IsConnected()
	{
		return pFunc->CallVFunc<bool>(27, this);
	}
	void FireEvents()
	{
		return pFunc->CallVFunc<void>(56, this);
	}
	bool IsTakingScreenShot()
	{
		return pFunc->CallVFunc<bool>(85, this);
	}
	void ClientCmd_Unrestricated(const char* string)
	{
		return pFunc->CallVFunc<void>(106, this, string);
	}
};


#endif