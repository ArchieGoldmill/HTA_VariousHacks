#pragma once

void __fastcall SetThrottle(ai::Vehicle* vehicle, int, float throttle, bool autobreak)
{
	if (vehicle->m_pPath) {
		if (vehicle->m_pathNum < vehicle->m_pPath->m_size - 1) {
			CVector velocity;
			vehicle->GetLinearVelocity(&velocity);

			float speedSquared = velocity * velocity;

			if (speedSquared > 1e-10f) {
				CVector forward;
				vehicle->GetDirection(&forward);
				float dot = forward * velocity;
				if (dot > 0.0f) {
					vehicle->SetThrottle(throttle, false);
					return;
				}
			}
		}
	}
	vehicle->SetThrottle(throttle, autobreak);
}

void InitAutoBrakeFix()
{
	injector::MakeCALL(0x005D3137, SetThrottle);
}
