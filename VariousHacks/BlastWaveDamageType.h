#pragma once
#include "BlastWave.h"
#include "BlastWavePrototypeInfo.h"
#include "XmlNode.h"

void __stdcall BlastWavePrototypeInfo_LoadFromXML(ai::BlastWavePrototypeInfoExtra* blastWavePrototypeInfo, m3d::cmn::XmlNode* xmlNode)
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

void __stdcall BlastWave_Ctor(ai::BlastWaveExtra* blastWave, ai::BlastWavePrototypeInfoExtra* blastWavePrototypeInfo)
{
	blastWave->m_DamageType = blastWavePrototypeInfo->m_DamageType;
}

void __declspec(naked) BlastWave_Ctor_Hook()
{
	static constexpr auto hExit = 0x007DF227;

	__asm
	{
		push ebx
		push esi
		push edi
		mov edi, [esp + 0x10];

		pushad;
		push edi;
		push ecx;
		call BlastWave_Ctor;
		popad;

		jmp hExit;
	}
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
	static constexpr auto hExit = 0x007DFAF7;

	__asm
	{
		mov eax, [edi + 0x164];
		mov[esp + 0x58], eax;

		jmp hExit;
	}
}

void InitBlastWaveDamageType()
{
	injector::WriteMemory<int>(0x005F81AC, sizeof(ai::BlastWavePrototypeInfoExtra)); // resize ai::BlastWavePrototypeInfo
	injector::WriteMemory<int>(0x007DF79D, sizeof(ai::BlastWaveExtra)); // resize ai::BlastWave

	injector::MakeJMP(0x007DF180, BlastWavePrototypeInfo_LoadFromXML_Hook);
	injector::MakeJMP(0x007DF220, BlastWave_Ctor_Hook);
	injector::MakeJMP(0x007DFAEF, CollideBlastWaveAndPhysicObj_Hook);
}