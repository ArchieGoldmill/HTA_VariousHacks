#pragma once
#include "GameImpulse.h"

namespace m3d
{
	struct Application
	{
		BYTE _offset[0x8B240];
		IImpulse* Impulse;

		static Application* Get()
		{
			return *(Application**)0x00A0A55C;
		}
	};
}