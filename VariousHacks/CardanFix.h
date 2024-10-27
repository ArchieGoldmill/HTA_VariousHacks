#pragma once
#include "Cabin.h"
#include "Basket.h"
#include "AnimInfo.h"

int RoughSign(float value)
{
    if (value > 0.000001)
        return 1;
    if (value >= -0.000001)
        return 0;
    return -1;
}

#define FLOAT_1_0 1.0f

void __fastcall _KeepThrottle(ai::Vehicle* vehicle, int, bool applyActions)
{
    int v3; // ecx
    int v4; // eax
    int v5; // eax
    int v6; // eax
    CVector* v7; // eax
    float x; // xmm2_4
    float y; // xmm1_4
    float z; // xmm0_4
    unsigned int v11; // eax
    ActionType* v12; // eax
    ai::Basket* v13; // eax
    ai::Basket* v14; // edi
    ai::Cabin* v15; // eax
    ai::Cabin* v16; // edi
    ActionType* v17; // eax
    ai::Basket* v18; // edi
    ai::Cabin* v19; // eax
    ai::Cabin* v20; // edi
    unsigned int m_flags; // eax
    ActionType* Myfirst; // eax
    ai::Basket* Basket; // eax
    ai::Basket* v24; // edi
    ai::Cabin* Cabin; // eax
    ai::Cabin* v26; // edi
    float wheelRpm; // [esp+8h] [ebp-28h]
    float vel; // [esp+Ch] [ebp-24h] BYREF
    float v29; // [esp+10h] [ebp-20h]
    float v30; // [esp+14h] [ebp-1Ch]
    CVector dir; // [esp+18h] [ebp-18h] BYREF
    char v32[12]; // [esp+24h] [ebp-Ch] BYREF

    wheelRpm = fabs(vehicle->m_averageWheelAVel) * 9.5492964;
    CVector velocity;
    vehicle->GetLinearVelocity(&velocity);

    vel = velocity.x;
    v29 = velocity.y;
    v30 = velocity.z;

    vehicle->GetDirection(&dir);
    if (vehicle->m_bAutoBrake)
    {
        if (wheelRpm > 5.0
            && (vehicle->m_engineRpm <= 0.000001 ? (vehicle->m_engineRpm >= -0.000001 ? (v3 = 0) : (v3 = -1)) : (v3 = 1),
                vehicle->m_throttle <= 0.000001 ? (vehicle->m_throttle >= -0.000001 ? (v4 = 0) : (v4 = -1)) : (v4 = 1),
                v3 * v4 <= 0)
            || wheelRpm <= 5.0
            && ((v5 = RoughSign(vehicle->m_throttle)) == 0
                || ((((dir.z * v30) + (dir.y * v29)) + (dir.x * vel)) * v5) < -1.5707964))
        {
            vehicle->m_throttle = 0.0;
            vehicle->m_brake = FLOAT_1_0;
        }
    }
    if (vehicle->m_throttle <= 0.000001 && vehicle->m_throttle >= -0.000001 && sqrt(v30 * v30 + v29 * v29 + vel * vel) < 0.5)
        vehicle->m_bHandBrake = 1;
    if (vehicle->m_bHandBrake)
    {
        vehicle->m_throttle = 0.0;
        vehicle->m_brake = FLOAT_1_0;
    }
    if (vehicle->m_engineRpm <= 0.000001)
    {
        if (vehicle->m_engineRpm >= -0.000001)
            v6 = 0;
        else
            v6 = -1;
    }
    else
    {
        v6 = 1;
    }
    vehicle->m_realThrottle = vehicle->m_throttle - ((v6 * vehicle->m_brake) * 10.0);
    if (applyActions)
    {
        if (vehicle->m_brake <= 0.0001)
        {
            m_flags = vehicle->GetMoveStatus();
            if ((m_flags & 8) == 0 && (m_flags & 2) == 0 && !vehicle->m_parentRepository)
            {
                Myfirst = vehicle->m_effectActions.data();
                if (Myfirst && *Myfirst != AT_MOVE1)
                {
                    *Myfirst = AT_MOVE1;
                    Basket = vehicle->GetBasket();
                    v24 = Basket;
                    if (Basket)
                    {
                        Basket->SetEffectActions(&vehicle->m_effectActions);
                        v24->SetNodeAnimAction(ActionType(2), 1);
                    }
                    Cabin = vehicle->GetCabin();
                    v26 = Cabin;
                    if (Cabin)
                    {
                        Cabin->SetEffectActions(&vehicle->m_effectActions);
                        v26->SetNodeAnimAction(ActionType(2), 1);
                    }
                    ai::Chassis* chassis = vehicle->GetChassis();
                    if (chassis)
                    {
                        m3d::AnimInfo* info;
                        chassis->Node->GetProperty(1, &info);
                        if (info)
                        {
                            bool has_anim = !info->m_Empty;
                            if (has_anim)
                            {
                                chassis->SetAnimationStopped(0);
                            }
                        }
                    }
                }
            }
        }
        else
        {
            CVector velocity2;
            v7 = vehicle->GetLinearVelocity(&velocity2);
            x = v7->x;
            y = v7->y;
            z = v7->z;
            v11 = vehicle->GetMoveStatus();
            if ((((x * x) + (y * y)) + (z * z)) >= 0.1)
            {
                if ((v11 & 8) == 0 && (v11 & 2) == 0 && !vehicle->m_parentRepository)
                {
                    v17 = vehicle->m_effectActions.data();
                    if (v17 && *v17 != AT_MOVE2)
                    {
                        *v17 = AT_MOVE2;
                        v18 = vehicle->GetBasket();
                        if (v18)
                        {
                            v18->SetEffectActions(&vehicle->m_effectActions);
                            v18->SetNodeAnimAction(ActionType(3), 1);
                        }
                        v19 = vehicle->GetCabin();
                        v20 = v19;
                        if (v19)
                        {
                            v19->SetEffectActions(&vehicle->m_effectActions);
                            v20->SetNodeAnimAction(ActionType(3), 1);
                        }
                        ai::Chassis* chassis = vehicle->GetChassis();
                        if (chassis)
                        {
                            m3d::AnimInfo* info;
                            chassis->Node->GetProperty(1, &info);
                            if (info)
                            {
                                bool has_anim = !info->m_Empty;
                                if (has_anim)
                                {
                                    chassis->SetAnimationStopped(0);
                                }
                            }
                        }
                    }
                }
            }
            else if ((v11 & 8) == 0 && (v11 & 2) == 0 && !vehicle->m_parentRepository)
            {
                v12 = vehicle->m_effectActions.data();
                if (v12 && *v12)
                {
                    *v12 = AT_STAND1;
                    v13 = vehicle->GetBasket();
                    v14 = v13;
                    if (v13)
                    {
                        v13->SetEffectActions(&vehicle->m_effectActions);
                        v14->SetNodeAnimAction(ActionType(0), 1);
                    }
                    v15 = vehicle->GetCabin();
                    v16 = v15;
                    if (v15)
                    {
                        v15->SetEffectActions(&vehicle->m_effectActions);
                        v16->SetNodeAnimAction(ActionType(0), 1);
                    }

                    ai::Chassis* chassis = vehicle->GetChassis();
                    if (chassis)
                    {
                        m3d::AnimInfo* info;
                        chassis->Node->GetProperty(1, &info);
                        if (info)
                        {
                            bool has_anim = !info->m_Empty;
                            if (has_anim)
                            {
                                chassis->SetAnimationStopped(1);
                            }
                        }
                    }
                }
            }
        }
    }
}


void InitCardanFix()
{
	injector::MakeCALL(0x005EC7AD, _KeepThrottle);
}