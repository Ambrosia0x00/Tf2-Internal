#pragma once
#ifndef DETOURS_HPP
#define DETOURS_HPP

#include"engineclient/engineclient.hpp"
#include"enginevgui/enginevgui.hpp"
#include"matpanel/matpanel.hpp"
#include"uniformstream/uniformstream.hpp"

class Detours
{
public:
	void Initialize();
}; inline Detours* pDetours;

inline void Detours::Initialize()
{
	EngineClient::Initialize();
	EngineVGui::Initialize();
	VGuiPanel::Initialize();
	Uniformstream::Initialize();
}

#endif