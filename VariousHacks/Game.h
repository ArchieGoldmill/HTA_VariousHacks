#pragma once
#define FUNC(address, return_t, callconv, name, ...) return_t (callconv* name)(__VA_ARGS__) = reinterpret_cast<decltype(name)>(address)
#define INLINE_FUNC(address, return_t, callconv, name, ...) inline return_t (callconv* name)(__VA_ARGS__) = reinterpret_cast<decltype(name)>(address)

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