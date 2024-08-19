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
	};

	struct BlastWavePrototypeInfoExtra : BlastWavePrototypeInfo
	{
		DamageType m_DamageType;
	};
}

ASSERT_SIZE(ai::BlastWavePrototypeInfo, 0x94);
ASSERT_SIZE(ai::BlastWavePrototypeInfoExtra, 0x98);