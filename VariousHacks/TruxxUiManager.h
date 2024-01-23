#pragma once
#include "WeaponGroupManager.h"
#include "GameImpulse.h"

struct TruxxUiManager
{
	char _offset[0x260];
	WeaponGroupManager* pWeaponGroupManager;

	void RemoveWindow(int wndId)
	{
		FUNC(0x00547B80, void, __thiscall, _RemoveWindow, TruxxUiManager*, int);
		_RemoveWindow(this, wndId);
	}
};

struct TruxxImpulse : m3d::GameImpulse
{

};