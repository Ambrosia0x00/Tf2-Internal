#pragma once
#ifndef PANEL_HPP
#define PANEL_HPP
#include"../surface/surface.hpp"

class MatSystemPanel_t
{
public:
	void SetMouseInputEnabled(vgui::VPanel vgui_panel, bool state)
	{
		return pFunc->CallVFunc<void>(32, this, vgui_panel, state);
	}
	const char* GetName(vgui::VPanel vgui_panel)
	{
		return pFunc->CallVFunc<const char*>(36, this, vgui_panel);
	}
	void SetTopMostPopup(vgui::VPanel vgui_panel, bool state)
	{
		return pFunc->CallVFunc<void>(39, this, vgui_panel, state);
	}
};
#endif