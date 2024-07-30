#pragma once
#include "DynamicScene.h"
#include "ObjContainer.h"
#include "Location.h"
#include "Kernel.h"

void __fastcall RenderDebugInfoHook(ai::DynamicScene* dynamicScene)
{
	dynamicScene->RenderDebugInfo();

	if (m3d::Kernel::Instance->m_engineConfig->m_ai_location_debug)
	{
		for (auto& node : ai::ObjContainer::Instance->AllObjects.Records)
		{
			if (node.m_value && node.m_value->IsKindOf(0x00A02818))
			{
				auto location = (ai::Location*)node.m_value;
				location->RenderDebugInfo();
			}
		}
	}
}

void InitLocationDebug()
{
	injector::MakeJMP(0x005C774E, RenderDebugInfoHook);
	injector::WriteMemory(0x0060AB7C, 0x00A02819); // disable vanilla render
}