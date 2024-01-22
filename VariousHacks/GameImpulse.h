#pragma once
#include "Object.h"

namespace m3d
{
	struct IImpulse
	{
		int vTalbe;
	};

	struct GameImpulse : IImpulse, m3d::Object
	{
		bool GetImpulseState(int impId)
		{
			FUNC(0x00597250, bool, __thiscall, _GetImpulseState, GameImpulse*, int);
			return _GetImpulseState(this, impId);
		}
	};
}