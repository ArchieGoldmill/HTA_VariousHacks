#pragma once
#include "ComplexPhysicObj.h"
#include "IzvratRepository.h"
#include "ActionType.h"
#include "VehiclePrototypeInfo.h"
#include "Basket.h"
#include "Cabin.h"
#include "Chassis.h"

namespace ai
{
	struct Vehicle : ComplexPhysicObj
	{
		BYTE _offset[0x100];
		float m_throttle;
		float m_brake;
		float m_realThrottle;
		float m_engineRpm;
		float m_averageEngineRpm;
		float m_driftCoeff;
		float m_averageWheelAVel;
		bool m_bAutoBrake;
		bool m_bHandBrake;
		BYTE _offset2[0x102];
		IzvratRepository* Repository;
		void* m_groundRepository;
		std::vector<ActionType> m_effectActions;

		float GetHealth()
		{
			FUNC(0x005D0BC0, float, __thiscall, _GetMaxHealth, Vehicle*);
			return _GetMaxHealth(this);
		}

		float GetMaxHealth()
		{
			FUNC(0x005D0C00, float, __thiscall, _GetMaxHealth, Vehicle*);
			return _GetMaxHealth(this);
		}

		float GetFuel()
		{
			FUNC(0x005D0C40, float, __thiscall, _GetFuel, Vehicle*);
			return _GetFuel(this);
		}

		float GetMaxFuel()
		{
			FUNC(0x005D0C80, float, __thiscall, _GetMaxFuel, Vehicle*);
			return _GetMaxFuel(this);
		}

		void ActivateHeadLights(bool bActivate)
		{
			FUNC(0x005DA130, void, __thiscall, _ActivateHeadLights, Vehicle*, bool);
			_ActivateHeadLights(this, bActivate);
		}

		CVector* GetLinearVelocity(CVector* result)
		{
			FUNC(0x005D11C0, CVector*, __thiscall, _GetLinearVelocity, Vehicle*, CVector*);
			return _GetLinearVelocity(this, result);
		}

		const ai::VehiclePrototypeInfo* GetPrototypeInfo()
		{
			FUNC(0x005DC890, const ai::VehiclePrototypeInfo*, __thiscall, _GetPrototypeInfo, Vehicle*);
			return _GetPrototypeInfo(this);
		}

		__int32 GetMoveStatus()
		{
			FUNC(0x005CBB10, __int32, __thiscall, _GetMoveStatus, Vehicle*);
			return _GetMoveStatus(this);
		}

		Basket* GetBasket()
		{
			FUNC(0x005CBA00, ai::Basket*, __thiscall, _GetBasket, Vehicle*);
			return _GetBasket(this);
		}

		Cabin* GetCabin()
		{
			FUNC(0x005CBA00, ai::Cabin*, __thiscall, _GetCabin, Vehicle*);
			return _GetCabin(this);
		}

		Chassis* GetChassis()
		{
			FUNC(0x005CB9A0, ai::Chassis*, __thiscall, _GetChassis, Vehicle*);
			return _GetChassis(this);
		}
	}; 
}