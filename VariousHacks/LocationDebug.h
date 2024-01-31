#pragma once
#include "DynamicScene.h"
#include "ObjContainer.h"
#include "Location.h"

void __fastcall RenderDebugInfoHook(ai::DynamicScene* dynamicScene)
{
	dynamicScene->RenderDebugInfo();

	for (auto& node : ai::ObjContainer::Instance->AllObjects.Records)
	{
		if (node.m_value && node.m_value->IsKindOf(0x00A02818))
		{
			auto location = (ai::Location*)node.m_value;
			location->RenderDebugInfo();
		}
	}
}

void InitLocationDebug()
{
	injector::MakeJMP(0x005C774E, RenderDebugInfoHook);
}