#pragma once
#include "SimplePhysicObj.h"
#include "DamageType.h"
#include "BlastWavePrototypeInfo.h"

namespace ai
{
	struct BlastWave : SimplePhysicObj
	{
		float m_WaveForceIntensity;
		float m_WaveDamageIntensity;
		int m_frameWhenCreated;
		int m_Frame;
		int m_rocketExplosionType;
		void* m_EffectNode;
		int m_emitterId;
		bool m_bCollided;
	};

	struct BlastWaveExtra : BlastWave
	{
		DamageType m_DamageType;
	};
}

ASSERT_SIZE(ai::BlastWave, 0x164);
ASSERT_SIZE(ai::BlastWaveExtra, 0x168);