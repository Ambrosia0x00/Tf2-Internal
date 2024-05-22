#pragma once
#ifndef ENGINEVGUI_HPP
#define ENGINEVGUI_HPP

#include"../../utils/vfunc/vfunc.hpp"
#include"../../includes/enums.hpp"

class EngineVGui_t
{
public:
	virtual ~EngineVGui_t(void) {}
	virtual unsigned int GetPanel(EVGuiPanel type) = 0;
	virtual bool IsGameUIVisable() = 0;
};

#endif