#pragma once
#include "Func.h"
#include "CStr.h"
#include "CVector.h"

namespace ai
{
	INLINE_FUNC(0x007D2F60, void, __fastcall, CommonGeomMovedCallback, int geomId);
}

INLINE_FUNC(0x0044BB40, void, __thiscall, Refuel, void*, int units);

inline void Repair(int units)
{
	static constexpr auto _Repair = 0x0044BBD0;

	__asm
	{
		mov eax, units;
		call _Repair;
	}
}

namespace ai
{
	INLINE_FUNC(0x006A9E70, int, __fastcall, DebugText, const CVector* p1, unsigned int color, float size, float height, const CStr* OutStr);
}