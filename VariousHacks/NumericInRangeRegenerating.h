#pragma once
#include "NumericInRange.h"

namespace ai
{
#pragma pack(push, 4)
	template <typename T>
	struct NumericInRangeRegenerating : NumericInRange<T>
	{
		__int64 m_BeforeRegenerate;
		__int64 m_AfterRegenerationChange;
		ai::Numeric<T> m_regeneration;
	};
#pragma pack(pop)
}