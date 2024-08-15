#pragma once
#include "CStr.h"
#include "SimplePhysicObjPrototypeInfo.h"
#include "DamageType.h"

namespace ai
{
	struct BlastWavePrototypeInfo : SimplePhysicObjPrototypeInfo
	{
		float m_WaveForceIntensity;
		float m_WaveDamageIntensity;
		CStr m_EffectName;
		DamageType m_DamageType; // Custom
	};
}