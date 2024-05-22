#pragma once

#include"../../utils/hooker/hooker.hpp"
#include"../../interfaces/interfaces.hpp"

typedef void(__fastcall* MatPanel_t)(void*, void*, unsigned int, bool, bool);
MatPanel_t MatPanelFn = 0;

namespace VGuiPanel
{
	namespace Paint
	{
		size_t index = 41;
		void __fastcall Detour(void* rbx, void* rsi, unsigned int panel,
			bool force_rep, bool allow_force)
		{
			return MatPanelFn(rbx, rsi, panel, force_rep, allow_force);
		}
	}
	void Initialize()
	{
		MatPanelFn = (MatPanel_t)pHook->vmt_hook(I::MatSystemPanel, Paint::index,
			(uintptr_t)Paint::Detour);
	}
}