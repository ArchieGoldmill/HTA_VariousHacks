#pragma once
#include "ThirdParty/Injector/injector.hpp"
#include "DragDropItemsWnd.h"
#include "CMiracle3d.h"
#include "PrototypeManager.h"
#include "Player.h"

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


void InitWareUse()
{
	injector::WriteMemory(0x009CB32C, OnMouseButton0Hook);
}