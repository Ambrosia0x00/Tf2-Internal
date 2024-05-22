#pragma once
#include"../../utils/hooker/hooker.hpp"
#include"../../interfaces/interfaces.hpp"

typedef bool(__stdcall* IsPlayingDemo_t)(void*, void*);
IsPlayingDemo_t IsPlayingDemoFn = 0;

namespace EngineClient
{
	namespace IsPlayingDemo
	{
		size_t index = 78;
		bool __stdcall Detour(void* rbx, void* rsi)
		{
			return IsPlayingDemoFn(rbx, rsi);
		}
	}

	void Initialize()
	{
		IsPlayingDemoFn = (IsPlayingDemo_t)pHook->vmt_hook(
			I::EngineClient, IsPlayingDemo::index, (uintptr_t)IsPlayingDemo::Detour
		);
	}
}