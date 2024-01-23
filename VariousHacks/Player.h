#pragma once
#include "Game.h"
#include "Vehicle.h"

namespace ai
{
	struct Player
	{
		inline static Player*& Instance = *(Player**)0x00A135E4;

		ai::Vehicle* GetVehicle()
		{
			FUNC(0x00651190, ai::Vehicle*, __thiscall, _GetVehicle, ai::Player*);
			return _GetVehicle(this);
		}
	};
}