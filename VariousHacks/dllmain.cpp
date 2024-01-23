#include <Windows.h>
#include "ThirdParty/Injector/injector.hpp"
#include "ThirdParty/IniReader/IniReader.h"

#include "Gun.h"
#include "CVector.h"
#include "Player.h"
#include "DragDropItemsWnd.h"
#include "CMiracle3d.h"
#include "PrototypeManager.h"

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

	ai::CommonGeomMovedCallback(gun->m_pGeoms.front()->m_geomId);
}

int __fastcall OnMouseButton0Hook(DragDropItemsWnd* dragDropItemsWnd, int, unsigned int state, const PointBase<float>* at)
{
	auto app = (CMiracle3d*)CMiracle3d::Get();
	auto impulse = (m3d::GameImpulse*)app->Impulse;

	if (!DragDropItemsWnd::DragSlot && impulse->CurKeys.IsThere(0x105)) // ctrl
	{
		ai::GeomRepositoryItem repositoryItem;
		dragDropItemsWnd->GetItemFromOrigin(&repositoryItem, at);
		if (repositoryItem.IsValid())
		{
			auto repositoryObj = repositoryItem.GetObj();
			if (repositoryObj && repositoryObj->IsKindOf(0x00A0238C))
			{
				CStr name;
				ai::PrototypeManager::Instance->GetPrototypeName(&name, repositoryObj->PrototypeId);
				if (name.allocSz && strcmp(name.charPtr, "potato"))
				{
					auto player = ai::Player::Get();
					if (player)
					{
						auto playerVehicle = player->GetVehicle();
						auto playerRepository = playerVehicle->Repository;
						if (playerRepository)
						{
							playerRepository->GiveUpThingByObjId(repositoryItem.ObjId);
							app->UiManager->RemoveWindow(0x24); // Info window

							return 1;
						}
					}
				}
			}
		}
	}

	return dragDropItemsWnd->OnMouseButton0(state, at);
}

void Init()
{
	CIniReader iniReader("VariousHacks.ini");

	GunsRotationTimeOut = iniReader.ReadFloat("GUNS_ROTATION", "TimeOut", 0);
	if (iniReader.ReadInteger("GUNS_ROTATION", "Enabled", 0) == 1 && GunsRotationTimeOut > 0)
	{
		WeaponGroupsToTrigger[0] = iniReader.ReadInteger("GUNS_ROTATION", "WeaponGroup_1", 0) == 1 ? 0x21 : 0;
		WeaponGroupsToTrigger[1] = iniReader.ReadInteger("GUNS_ROTATION", "WeaponGroup_2", 0) == 1 ? 0x22 : 0;
		WeaponGroupsToTrigger[2] = iniReader.ReadInteger("GUNS_ROTATION", "WeaponGroup_3", 0) == 1 ? 0x23 : 0;
		WeaponGroupsToTrigger[3] = iniReader.ReadInteger("GUNS_ROTATION", "WeaponGroup_4", 0) == 1 ? 0x24 : 0;
		WeaponGroupsToTrigger[4] = iniReader.ReadInteger("GUNS_ROTATION", "WeaponGroup_5", 0) == 1 ? 0x25 : 0;
		WeaponGroupsToTrigger[5] = iniReader.ReadInteger("GUNS_ROTATION", "WeaponGroup_All", 0) == 1 ? 0x26 : 0;

		injector::MakeJMP(0x006E1C80, LookAtPointHook);
	}

	if (iniReader.ReadInteger("GENERAL", "AllowMoreQuestIcons", 0) == 1)
	{
		injector::WriteMemory<BYTE>(0x0056BF09, 0xEB);
	}

	injector::WriteMemory(0x009CB32C, OnMouseButton0Hook);
}

BOOL APIENTRY DllMain(HMODULE, DWORD reason, LPVOID)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		Init();
	}

	return TRUE;
}