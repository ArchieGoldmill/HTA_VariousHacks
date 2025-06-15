#pragma once
#include <string>
#include "ThirdParty/Injector/injector.hpp"
#include "Impulse.h"
#include "kernel.h"

std::string LuaScripts[10];

void ExecuteLuaScripts()
{
	auto impulse = (m3d::GameImpulse*)CMiracle3d::Instance->Impulse;
	auto scriptServer = m3d::Kernel::Instance->m_scriptServer;

	for (int impId = IM_DEBUG_0; impId <= IM_DEBUG_9; impId++)
	{
		if (impulse->GetImpulseStateAndReset(impId))
		{
			scriptServer->Execute(LuaScripts[impId - IM_DEBUG_0].c_str(), "VariousHacks");
		}
	}
}

void __declspec(naked) LuaScripts_Hook()
{
	__asm
	{
		pushad;
		call ExecuteLuaScripts;
		popad;

		ret 8;
	}
}

void InitLuaScripts()
{
	injector::MakeJMP(0x00401B37, LuaScripts_Hook);
}