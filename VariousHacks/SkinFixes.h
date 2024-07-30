#pragma once
#include "Messages.h"

void __fastcall SetSkinHook(ai::PhysicBody* physicBody, int, int skin)
{
	auto owner = physicBody->OwnerPhysicObj;
	if (owner)
	{
		owner->SkinNumber = skin;
	}

	if (physicBody->Node)
	{
		physicBody->Node->SetProperty(PROP_DM_SKIN, &skin);
	}

	if (physicBody->IsKindOf(0x00A02354))
	{
		auto gun = (ai::Gun*)physicBody;
		if (gun->BarrelNode)
		{
			gun->BarrelNode->SetProperty(PROP_DM_SKIN, &skin);
		}
	}
}

void InitSkinFixes()
{
	injector::MakeJMP(0x006165C0, SetSkinHook);
}