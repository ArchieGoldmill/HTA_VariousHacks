#pragma once
#include "VehiclePart.h"

namespace ai
{
	struct Chassis : VehiclePart // sizeof=0x478
	{
		ai::NumericInRangeRegenerating<float> m_health;
		ai::NumericInRangeRegenerating<float> m_fuel;
	};
}