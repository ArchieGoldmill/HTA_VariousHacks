#pragma once
#include "Application.h"
#include "TruxxUiManager.h"

struct CMiracle3d : m3d::Application
{
	char _offset[0x2A8];
	TruxxUiManager* UiManager;
};