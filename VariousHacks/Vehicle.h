#pragma once
#include "ComplexPhysicObj.h"
#include "IzvratRepository.h"
#include "ActionType.h"

namespace ai
{
	struct Vehicle : ComplexPhysicObj
	{
		BYTE _offset[0x220];
		IzvratRepository* Repository;
		void* m_groundRepository;
		std::vector<ActionType> m_effectActions;

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

		void ActivateHeadLights(bool bActivate)
		{
			FUNC(0x005DA130, void, __thiscall, _ActivateHeadLights, Vehicle*, bool);
			_ActivateHeadLights(this, bActivate);
		}
	};
}