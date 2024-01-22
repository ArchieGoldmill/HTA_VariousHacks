#pragma once
#include "Numeric.h"

namespace ai
{
#pragma pack(push, 4)
	template <typename T>
	struct NumericInRange : Component<T>
	{
		__int64 m_BeforeValueApplyModifier;
		__int64 m_BeforeMinValueApplyModifier;
		__int64 m_BeforeMaxValueApplyModifier;
		__int64 m_BeforeValueChange;
		__int64 m_BeforeMinValueChange;
		__int64 m_BeforeMaxValueChange;
		__int64 m_AfterValueChange;
		__int64 m_AfterMinValueChange;
		__int64 m_AfterMaxValueChange;
		ai::Numeric<T> m_value;
		ai::Numeric<T> m_minValue;
		ai::Numeric<T> m_maxValue;
	};
#pragma pack(pop)
}