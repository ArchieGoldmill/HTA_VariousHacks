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
		DamageType m_DamageType; // Custom

		void Ctor(ai::BlastWavePrototypeInfo* prototypeInfo)
		{
			FUNC(0x007DF220, void, __thiscall, _Ctor, BlastWave*, ai::BlastWavePrototypeInfo*);
			_Ctor(this, prototypeInfo);
		}
	};
}