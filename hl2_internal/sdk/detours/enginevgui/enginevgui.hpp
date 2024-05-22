#pragma once

#include"../../utils/hooker/hooker.hpp"
#include"../../interfaces/interfaces.hpp"

typedef void(__fastcall* Paint_t)(void*, void*, int);
Paint_t PaintFn = 0;

namespace EngineVGui
{
	namespace Paint
	{
		size_t index = 14;
		void __fastcall Detour(void* rbx, void* rsi, int mode)
		{
			//TODO: render menu
			return PaintFn(rbx, rsi, mode);
		}
	}

	void Initialize()
	{
		PaintFn = (Paint_t)pHook->vmt_hook(I::EngineVGui, Paint::index, 
			(uintptr_t)Paint::Detour);
	}
}