#pragma once
#include <map>
#include <set>

#include "Object.h"

struct WeaponGroup : m3d::Object
{
	int GroupId;
	int ImpulseId;
	std::set<CStr> GunPartNames;
};

struct WeaponGroupManager : m3d::Object
{
	std::map<WeaponGroup*, int> WeaponGroups;
	std::map<WeaponGroup*, int> SavedWeaponGroups;
};