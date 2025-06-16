#pragma once
#include "CStr.h"
#include "ComplexPhysicObjPrototypeInfo.h"

namespace ai
{
	struct VehiclePrototypeInfo : ComplexPhysicObjPrototypeInfo // sizeof=0x12C
	{
		BYTE _offset[0x10]; // std::vector<ai::VehiclePrototypeInfo::WheelInfo> m_wheelInfos;
		float m_diffRatio;
		float m_maxEngineRpm;
		float m_lowGearShiftLimit;
		float m_highGearShiftLimit;
		float m_selfBrakingCoeff;
		float m_steeringSpeed;
		int m_decisionMatrixNum;
		float m_takingRadius;
		unsigned __int8 m_priority;
		BYTE _offset2[0x3];
		CStr m_hornSoundName;
		float m_cameraHeight;
		float m_cameraMaxDist;
		CStr m_destroyEffectNames[4];
		int m_blastWavePrototypeId;
		float m_additionalWheelsHover;
		float m_driftCoeff;
		float m_pressingForce;
		float m_healthRegeneration;
		float m_durabilityRegeneration;
		CStr m_blastWavePrototypeName;
	};
}

ASSERT_SIZE(ai::VehiclePrototypeInfo, 0x12C);