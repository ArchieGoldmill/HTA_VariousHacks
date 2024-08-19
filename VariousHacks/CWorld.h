#pragma once
#include "WeatherManager.h"

namespace m3d
{
	struct CWorld
	{
		BYTE _offset[0x39E99C];
		WeatherManager m_weatherManager;
	};
}