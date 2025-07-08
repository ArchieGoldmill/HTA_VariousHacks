#pragma once

void __fastcall SetThrottle(ai::Vehicle* vehicle, int, float throttle, bool autobreak)
{
	if (vehicle->m_pPath) {
		if (vehicle->m_pathNum < vehicle->m_pPath->m_size - 1) {
			vehicle->SetThrottle(throttle, false);
			return;
		}
	}
	vehicle->SetThrottle(throttle, autobreak);
}

void InitAutoBrakeFix()
{
	injector::MakeCALL(0x005D3137, SetThrottle);
}
