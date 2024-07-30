#pragma once
#include "WeatherManager.h"

namespace m3d
{
	struct CWorld
	{
		BYTE _offset[0x39E980];
		WeatherManager* m_weatherManager;
	};
}