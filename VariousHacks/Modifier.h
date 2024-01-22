#pragma once
#include "CStr.h"
#include "AIParam.h"

namespace ai
{
	struct Modifier
	{
		float timeOut;
		int Operation;
		int m_magicPrototypeId;
		CStr PropertyName;
		int SenderID;
		m3d::AIParam Value;
	};
}