#pragma once
#include "Object.h"
#include <vector>

namespace ai
{
	struct ComplexPhysicObjPartDescription : m3d::Object
	{
		int m_partResourceId;
		std::vector<CStr, std::allocator<CStr>> m_lpNames;
	};
}

ASSERT_SIZE(ai::ComplexPhysicObjPartDescription, 0x48);