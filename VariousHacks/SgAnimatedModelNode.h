#pragma once

#include <vector>
#include <Windows.h>

#include "SgNode.h"
#include "ActionType.h"

namespace m3d
{
	struct SgAnimatedModelNode : SgNode
	{
		BYTE _offset[0x1D4 - sizeof(SgNode)];
		ActionType m_action;
		std::vector<ActionType> m_effectActions;
	};
}