#pragma once
#include "WeaponGroupManager.h"
#include "GameImpulse.h"

struct TruxxUiManager
{
	char _offset[0x260];
	WeaponGroupManager* pWeaponGroupManager;
};

struct TruxxImpulse : m3d::GameImpulse
{

};