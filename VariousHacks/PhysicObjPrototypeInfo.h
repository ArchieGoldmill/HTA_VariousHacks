#pragma once
#include "PrototypeInfo.h"

namespace ai
{
	struct PhysicObjPrototypeInfo : PrototypeInfo
	{
		float m_intersectionRadius;
		float m_lookRadius;
	};

	ASSERT_SIZE(ai::PhysicObjPrototypeInfo, 0x48);
}