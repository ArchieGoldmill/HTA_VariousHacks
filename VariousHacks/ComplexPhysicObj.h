#pragma once
#include "PhysicObj.h"

namespace ai
{
	struct ComplexPhysicObj : ai::PhysicObj
	{
		std::map<CStr, ai::VehiclePart*> m_vehicleParts;

		ai::VehiclePart* GetPartByName(const CStr* partName)
		{
			FUNC(0x006BF720, ai::VehiclePart*, __thiscall, _GetPartByName, ai::ComplexPhysicObj*, const CStr*);
			return _GetPartByName(this, partName);
		}
	};
}