#pragma once
#include "Vehicle.h"
#include "Unmap.h"
#include "ActionType.h"
#include "Messages.h"
#include "SgAnimatedModelNode.h"
#include "StaticAutoGun.h"
#include "CClient.h"

void __fastcall Gun_SetNodeAction(ai::Gun* gun, int, ActionType action, bool forceRestartAction)
{
	auto barrel = gun->BarrelNode;

	std::vector<ActionType> actionsBackup;

	if (barrel)
	{
		if (barrel->IsKindOf(0x00A02978)) // m3d::SgAnimatedModelNode
		{
			auto sgBarrel = (m3d::SgAnimatedModelNode*)barrel;
			actionsBackup = sgBarrel->m_effectActions;
		}
	}

	gun->SetNodeAction(action, forceRestartAction);

	if (actionsBackup.size() > 1)
	{
		gun->BarrelNode->SetProperty(PROP_DM_ADD_EFFECT_ACTION, &actionsBackup[1]);
	}
}

void ActivateHeadLightsPart(ai::VehiclePart* part, bool bActivate)
{
	if (part->IsKindOf(0x00A02354))
	{
		std::vector<ActionType> actions = { AT_STAND1, bActivate ? AT_RESERVED2 : AT_RESERVED1 };

		auto gun = (ai::Gun*)part;
		gun->SetEffectActions(&actions);

		auto barrel = gun->BarrelNode;
		if (barrel)
		{
			barrel->SetProperty(PROP_DM_ARRAY_EFFECT_ACTIONS, &actions);
		}
	}
}

void __fastcall ActivateHeadLights(ai::Vehicle* vehicle, int, bool bActivate)
{
	ActionType ogAction = vehicle->m_effectActions[1];
	vehicle->ActivateHeadLights(bActivate);
	if (ogAction == AT_RESERVED2 && bActivate)
	{
		return;
	}

	if (ogAction == AT_RESERVED1 && !bActivate)
	{
		return;
	}

	auto parts = (Unmap<CStr, ai::VehiclePart*>*) & vehicle->m_vehicleParts;

	auto v4 = parts->_Myhead->_Left;
	auto i = v4;
	auto j = v4;
	if (parts->_Myhead->_Left != parts->_Myhead)
	{
		do
		{
			ActivateHeadLightsPart(v4->_Myval.second, bActivate);
			if (!v4->_Isnil)
			{
				auto v5 = v4->_Right;
				if (v5->_Isnil)
				{
					for (i = v4->_Parent; !i->_Isnil; i = i->_Parent)
					{
						if (v4 != i->_Right)
							break;
						v4 = i;
					}
					v4 = i;
				}
				else
				{
					v4 = v4->_Right;
					for (j = v5->_Left; !j->_Isnil; j = j->_Left)
						v4 = j;
				}
			}
		} while (v4 != parts->_Myhead);
	}
}

void __stdcall StaticAutoGun_Update(ai::StaticAutoGun* staticGun)
{
	auto gun = (ai::Gun*)staticGun->GetPartByName((CStr*)0x00A1ACAC);

	if (gun)
	{
		bool enable = m3d::CClient::Instance->m_world->m_weatherManager.m_curDayTime == m3d::GTP_NIGHT_TIME;
		ActivateHeadLightsPart(gun, enable);
	}
}

void __declspec(naked) StaticAutoGun_Update_Hook()
{
	static constexpr auto hExit = 0x00743747;

	__asm
	{
		pushad;
		push ecx;
		call StaticAutoGun_Update;
		popad;

		mov eax, [esp + 0x08];
		sub esp, 0x20;

		jmp hExit;
	}
}

void InitGunLights()
{
	injector::MakeCALL(0x004018D6, ActivateHeadLights);
	injector::MakeCALL(0x005EC7F1, ActivateHeadLights);

	injector::MakeNOP(0x006DE1F0, 6);
	injector::MakeCALL(0x006DE1F0, Gun_SetNodeAction);

	injector::MakeNOP(0x006DE20C, 6);
	injector::MakeCALL(0x006DE20C, Gun_SetNodeAction);

	injector::MakeNOP(0x006DE24B, 6);
	injector::MakeCALL(0x006DE24B, Gun_SetNodeAction);

	injector::MakeNOP(0x006DE26B, 6);
	injector::MakeCALL(0x006DE26B, Gun_SetNodeAction);

	injector::MakeNOP(0x006DE2B2, 6);
	injector::MakeCALL(0x006DE2B2, Gun_SetNodeAction);

	injector::MakeJMP(0x00743740, StaticAutoGun_Update_Hook);
}