#pragma once
#include <Windows.h>
#include "EngineConfig.h"
#include "ScriptServer.h"

namespace m3d
{
	struct Kernel
	{
		inline static Kernel*& Instance = *(Kernel**)0x00A0988C;

		BYTE _offset[0x10];
		EngineConfig* m_engineConfig;
		ScriptServer* m_scriptServer;
	};
}