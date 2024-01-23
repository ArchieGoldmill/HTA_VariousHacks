#pragma once
#include "GameImpulse.h"
#include "CMiracle3d.h"
#include "Gun.h"

float GunsRotationTimeOut;
int WeaponGroupsToTrigger[6];

bool IsTryingToFire()
{
	auto impulse = (m3d::GameImpulse*)CMiracle3d::Get()->Impulse;
	for (int i = 0; i < 6; i++) // from IM_CAR_FIRE_0 to IM_CAR_FIRE_ALL
	{
		int impId = WeaponGroupsToTrigger[i];
		if (impId && impulse->GetImpulseState(impId))
		{
			return true;
		}
	}

	return false;
}

bool IsPlayerGun(ai::Gun* gun)
{
	return gun->OwnerPhysicObj == ai::Player::Instance->GetVehicle();
}

bool IsGunTimedOut(ai::Gun* gun)
{
	if (IsPlayerGun(gun) && gun->m_timeFromLastShot > GunsRotationTimeOut)
	{
		if (IsTryingToFire())
		{
			gun->m_timeFromLastShot = 0.0f;
		}
		else
		{
			return true;
		}
	}

	return false;
}

void __fastcall LookAtPointHook(ai::Gun* gun, int, const CVector* lookAt, float elapsedTime)
{
	Quaternion quatHorizRotation;
	Quaternion quatElevation;

	if (IsGunTimedOut(gun))
	{
		Quaternion currentRotation;
		gun->GetNodeRelativeRotation(&currentRotation);

		Quaternion initial;
		initial.Zero();
		initial.RotY(gun->InitialHorizAngle);

		float time = elapsedTime * gun->TurningSpeed * 2;
		quatHorizRotation.Slerp(&currentRotation, &initial, time);

		if (gun->BarrelNode)
		{
			initial.Zero();
			quatElevation.Slerp(gun->BarrelNode->GetRotation(), &initial, time);
		}
	}
	else
	{
		float alpha, beta;
		gun->GetOffsetAngles(lookAt, elapsedTime, &alpha, &beta);

		quatHorizRotation.RotY(alpha);

		if (gun->BarrelNode)
		{
			quatElevation.RotX(-beta);
		}
	}

	gun->SetNodeRelativeRotation(&quatHorizRotation);
	if (gun->BarrelNode)
	{
		gun->BarrelNode->SetRotation(&quatElevation);
	}

	if (gun->m_pGeoms.size())
	{
		ai::CommonGeomMovedCallback(gun->m_pGeoms.front()->m_geomId);
	}
}

void InitGunRotation()
{
	injector::MakeJMP(0x006E1C80, LookAtPointHook);
}