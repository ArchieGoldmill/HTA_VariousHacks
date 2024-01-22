#pragma once
#include "VehiclePart.h"
#include "Game.h"

namespace ai
{
	struct Gun : VehiclePart
	{
		float m_leftStopAngle;
		float m_rightStopAngle;
		float m_lowStopAngle;
		float m_highStopAngle;
		int m_targetObjId;
		int m_damage;
		int m_curBarrelIndex;
		float m_currentDesiredAlpha;
		float m_timeFromLastShot;
		bool m_bIsFiring;
		int m_shellPrototypeId;
		int m_damageType;
		float m_firingRate;
		float m_firingRange;
		float m_recoilForce;
		float TurningSpeed;
		float m_ChargeSize;
		float m_ReChargingTime;
		float m_ReChargingTimePerShell;
		float m_ShellsInPool;
		float m_ChargeState;
		float m_CurrentReChargingTime;
		float m_ShellsInCurrentCharge;
		m3d::SgNode* BarrelNode;
		bool m_bWasShot;
		bool m_bJustShot;
		float InitialHorizAngle;

		void GetOffsetAngles(const CVector* lookAt, float elapsedTime, float* alpha, float* beta)
		{
			FUNC(0x006DEA40, void, __thiscall, _GetOffsetAngles, ai::Gun*, const CVector*, float, float*, float*);
			_GetOffsetAngles(this, lookAt, elapsedTime, alpha, beta);
		}
	};
}