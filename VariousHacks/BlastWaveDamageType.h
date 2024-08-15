#pragma once
#include "BlastWave.h"
#include "BlastWavePrototypeInfo.h"
#include "XmlNode.h"

void __stdcall BlastWavePrototypeInfo_LoadFromXML(ai::BlastWavePrototypeInfo* blastWavePrototypeInfo, m3d::cmn::XmlNode* xmlNode)
{
	ai::DamageType damageType = ai::DAMAGE_BLAST;

	if (!xmlNode->IsEmpty())
	{
		auto damageTypeAttr = xmlNode->GetAttribute("DamageType");
		if (damageTypeAttr)
		{
			if (strcmp(damageTypeAttr, "PIERCING") == 0)
			{
				damageType = ai::DAMAGE_PIERCING;
			}

			if (strcmp(damageTypeAttr, "BLAST") == 0)
			{
				damageType = ai::DAMAGE_BLAST;
			}

			if (strcmp(damageTypeAttr, "ENERGY") == 0)
			{
				damageType = ai::DAMAGE_ENERGY;
			}

			if (strcmp(damageTypeAttr, "WATER") == 0)
			{
				damageType = ai::DAMAGE_WATER;
			}
		}
	}

	blastWavePrototypeInfo->m_DamageType = damageType;
}

void __fastcall BlastWave_Ctor(ai::BlastWave* blastWave, int, ai::BlastWavePrototypeInfo* blastWavePrototypeInfo)
{
	blastWave->Ctor(blastWavePrototypeInfo);

	blastWave->m_DamageType = blastWavePrototypeInfo->m_DamageType;
}

void __declspec(naked) BlastWavePrototypeInfo_LoadFromXML_Hook()
{
	static constexpr auto hExit = 0x007DF185;

	__asm
	{
		pushad;
		push[esp + 0x2C];
		push ecx;
		call BlastWavePrototypeInfo_LoadFromXML;
		popad;

		mov eax, [esp + 0x04];
		push esi;

		jmp hExit;
	}
}

void __declspec(naked) CollideBlastWaveAndPhysicObj_Hook()
{
	static constexpr auto hExit = 0x007DFADD;

	__asm
	{
		mov eax, [edi + 0x164];
		mov byte ptr[esp + 0x4C], al;

		jmp hExit;
	}
}

void InitBlastWaveDamageType()
{
	injector::WriteMemory<int>(0x005F81AC, 0x98); // resize ai::BlastWavePrototypeInfo
	injector::WriteMemory<int>(0x007DF79D, 0x168); // resize ai::BlastWave

	injector::MakeJMP(0x007DF180, BlastWavePrototypeInfo_LoadFromXML_Hook);
	injector::MakeCALL(0x007DF7AB, BlastWave_Ctor);
	injector::MakeJMP(0x007DFAD8, CollideBlastWaveAndPhysicObj_Hook);
}