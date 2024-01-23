#pragma once
#include "ComplexPhysicObj.h"
#include "IzvratRepository.h"

namespace ai
{
	struct Vehicle : ComplexPhysicObj
	{
		BYTE _offset[0x28C];
		IzvratRepository* Repository;

		float GetHealth()
		{
			FUNC(0x005D0BC0, float, __thiscall, _GetMaxHealth, Vehicle*);
			return _GetMaxHealth(this);
		}

		float GetMaxHealth()
		{
			FUNC(0x005D0C00, float, __thiscall, _GetMaxHealth, Vehicle*);
			return _GetMaxHealth(this);
		}

		float GetFuel()
		{
			FUNC(0x005D0C40, float, __thiscall, _GetFuel, Vehicle*);
			return _GetFuel(this);
		}
		
		float GetMaxFuel()
		{
			FUNC(0x005D0C80, float, __thiscall, _GetMaxFuel, Vehicle*);
			return _GetMaxFuel(this);
		}
	};
}