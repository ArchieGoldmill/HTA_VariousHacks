#pragma once
#include "VehiclePart.h"

namespace ai
{
	struct Cabin : VehiclePart
	{
		float m_maxPower;
		float m_maxTorque;
		float m_maxSpeed;
		float m_fuelConsumption;
		int m_maxGadgets;
		float m_control;
	};
}