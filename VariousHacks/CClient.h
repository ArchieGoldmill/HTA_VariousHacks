#pragma once
#include <Windows.h>
#include "CWorld.h"

namespace m3d
{
	struct CClient
	{
		inline static CClient*& Instance = *(CClient**)0x00A1185C;

		BYTE _offset[0x8];
		CWorld* m_world;
	};
}