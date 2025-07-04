#pragma once
#include <string>
#include "ThirdParty/Injector/injector.hpp"
#include "DragDropItemsWnd.h"
#include "CMiracle3d.h"
#include "PrototypeManager.h"
#include "Player.h"

struct WareUnits
{
	float Units;
	std::string Ware;
};

std::vector< WareUnits*> RepairWares;
std::vector< WareUnits*> RefuelWares;

bool TryRepair(ai::Vehicle* playerVehicle, CStr& name)
{
	for (auto wu : RepairWares)
	{
		if (name.Equal(wu->Ware.c_str()))
		{
			float current = playerVehicle->GetHealth();
			float max = playerVehicle->GetMaxHealth();

			if (current >= max)
			{
				return false;
			}

			float amount = wu->Units;
			if (current + amount > max)
			{
				amount = max - current;
			}


			Repair(amount);
			return true;
		}
	}

	return false;
}

bool TryRefuel(ai::Vehicle* playerVehicle, CStr& name)
{
	for (auto wu : RefuelWares)
	{
		if (name.Equal(wu->Ware.c_str()))
		{
			float current = playerVehicle->GetFuel();
			float max = playerVehicle->GetMaxFuel();

			if (current >= max)
			{
				return false;
			}

			float amount = wu->Units;
			if (current + amount > max)
			{
				amount = max - current;
			}

			Refuel(nullptr, amount);
			return true;
		}
	}

	return false;
}

int __fastcall OnMouseButton0Hook(DragDropItemsWnd* dragDropItemsWnd, int, unsigned int state, const PointBase<float>* at)
{
	auto app = CMiracle3d::Instance;
	auto impulse = (m3d::GameImpulse*)app->Impulse;

	if (!DragDropItemsWnd::DragSlot && impulse->CurKeys.IsThere(0x105)) // ctrl
	{
		ai::GeomRepositoryItem repositoryItem;
		dragDropItemsWnd->GetItemFromOrigin(&repositoryItem, at);
		if (repositoryItem.IsValid())
		{
			auto repositoryObj = repositoryItem.GetObj();
			if (repositoryObj && repositoryObj->IsKindOf(0x00A0238C)) // Ware class
			{
				CStr name;
				ai::PrototypeManager::Instance->GetPrototypeName(&name, repositoryObj->PrototypeId);

				auto playerVehicle = ai::Player::Instance->GetVehicle();
				if (TryRepair(playerVehicle, name) || TryRefuel(playerVehicle, name))
				{
					playerVehicle->Repository->GiveUpThingByObjId(repositoryItem.ObjId);
					app->UiManager->RemoveWindow(0x24); // Info window
					return 1;
				}
			}
		}
	}

	return dragDropItemsWnd->OnMouseButton0(state, at);
}

void InitWareUse()
{
	injector::WriteMemory(0x009CB32C, OnMouseButton0Hook);
}