#pragma once
#include "Application.h"
#include "TruxxUiManager.h"

struct CMiracle3d : m3d::Application
{
	inline static CMiracle3d*& Instance = *(CMiracle3d**)0x00A0A55C;

	char _offset[0x2A8];
	TruxxUiManager* UiManager;
};