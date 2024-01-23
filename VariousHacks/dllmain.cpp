#include <Windows.h>
#include "ThirdParty/Injector/injector.hpp"
#include "ThirdParty/IniReader/IniReader.h"

#include "Gun.h"
#include "CVector.h"
#include "Player.h"
#include "WeaponGroupManager.h"
#include "CMiracle3d.h"

float GunsTimeOut;

bool IsTryingToFire()
{
	auto impulse = (m3d::GameImpulse*)CMiracle3d::Get()->Impulse;
	for (int i = 0x21; i <= 0x26; i++) // from IM_CAR_FIRE_0 to IM_CAR_FIRE_ALL
	{
		if (impulse->GetImpulseState(i))
		{
			return true;
		}
	}

	return false;
}

bool IsPlayerGun(ai::Gun* gun)
{
	auto gunOwner = gun->OwnerPhysicObj;
	auto player = ai::Player::Get();
	if (gunOwner && player)
	{
		auto playerVehicle = player->GetVehicle();
		return gunOwner == playerVehicle;
	}

	return false;
}

bool IsGunTimedOut(ai::Gun* gun)
{
	if (IsPlayerGun(gun) && gun->m_timeFromLastShot > GunsTimeOut)
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

	ai::CommonGeomMovedCallback(gun->m_pGeoms.front()->m_geomId);
}

void Init()
{
	CIniReader iniReader("VariousHacks.ini");

	GunsTimeOut = iniReader.ReadFloat("GENERAL", "GunsRotationTimeOut", 0);
	if (iniReader.ReadInteger("GENERAL", "GunsRotation", 0) == 1 && GunsTimeOut > 0)
	{
		injector::MakeJMP(0x006E1C80, LookAtPointHook);
	}

	if (iniReader.ReadInteger("GENERAL", "AllowMoreQuestIcons", 0) == 1)
	{
		injector::WriteMemory<BYTE>(0x0056BF09, 0xEB, true);
	}
}

BOOL APIENTRY DllMain(HMODULE, DWORD reason, LPVOID)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		Init();
	}

	return TRUE;
}