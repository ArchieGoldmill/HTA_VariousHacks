#pragma once
#include "PrototypeInfo.h"

namespace ai
{
	struct PhysicObjPrototypeInfo : PrototypeInfo
	{
		float m_intersectionRadius;
		float m_lookRadius;
	};
}