#pragma once

void __stdcall UpdateWeather()
{
    m3d::CClient::Instance->m_world->m_weatherManager.UpdateDayTime();
}

void __declspec(naked) UpdateWeatherHook()
{
    __asm {

        pushad;
        call UpdateWeather;
        popad;

        add esp, 2C0h;

        retn 8;
    }
}

void InitPostEffectReload()
{
    injector::MakeNOP(0x0041F433, 9);
    injector::MakeJMP(0x0041F433, UpdateWeatherHook);
}