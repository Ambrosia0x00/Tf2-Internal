#pragma once
#ifndef INTERFACES_HPP
#define INTERFACES_HPP
#include"../hl2_src/hl2_src.hpp"
#include"../../utils/capture/capture.hpp"

namespace I
{
	AppSystem_t* AppSystem = nullptr;
	EntityList_t* EntityList = nullptr;
	EngineClient_t* EngineClient = nullptr;
	EngineVGui_t* EngineVGui = nullptr;
	ICvar_t* Cvar = nullptr;
	MatSystemSurface_t* MatSystemSurface = nullptr;
	MatSystemPanel_t* MatSystemPanel = nullptr;
	UniformStream_t* UniformStream = nullptr;
}

class Interfaces
{
public:
	void Initialize();
}; inline Interfaces* pInterfaces;

inline void Interfaces::Initialize()
{
	I::BaseClient = pCapture->CaptureInterface<BaseClient_t*>(L"client.dll", "VClient017");
	I::EntityList = pCapture->CaptureInterface<EntityList_t*>(L"client.dll", "VClientEntityList003");
	I::EngineClient = pCapture->CaptureInterface<EngineClient_t*>(L"engine.dll", "VEngineClient014");
	I::EngineVGui = pCapture->CaptureInterface<EngineVGui_t*>(L"engine.dll", "VEngineVGui002");
	I::Cvar = pCapture->CaptureInterface<ICvar_t*>(L"vstdlib.dll", "VEngineCvar004");
	I::MatSystemSurface = pCapture->CaptureInterface<MatSystemSurface_t*>(L"vguimatsurface.dll", "VGUI_Surface030");
	I::MatSystemPanel = pCapture->CaptureInterface<MatSystemPanel_t*>(L"vgui2.dll", "VGUI_Panel009");
	I::UniformStream = pCapture->CaptureInterface<UniformStream_t*>(L"engine.dll", "VEngineRandom001");
}

#endif