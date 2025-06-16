#pragma once
#include "PhysicObjPrototypeInfo.h"
#include "ComplexPhysicObjPartDescription.h"
#include "CVector.h"
#include <map>
#include <minwindef.h>

namespace ai
{
	struct ComplexPhysicObjPrototypeInfo : PhysicObjPrototypeInfo
	{
		std::map<CStr, int, std::less<CStr>, std::allocator<std::pair<CStr const, int>>> m_partPrototypeIds;
		CVector m_massSize;
		CVector m_massTranslation;
		BYTE _offset[0x24];
	};
}

ASSERT_SIZE(ai::ComplexPhysicObjPrototypeInfo, 0x90);
