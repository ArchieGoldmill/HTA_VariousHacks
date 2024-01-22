#pragma once
#include "Component.h"

namespace ai
{
#pragma pack(push, 4)
	template <typename T>
	struct Numeric : Component<T>
	{
		__int64 m_BeforeApplyModifier;
		T m_value;
	};
#pragma pack(pop)
}