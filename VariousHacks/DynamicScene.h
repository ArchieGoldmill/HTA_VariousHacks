#pragma once

namespace ai
{
	struct DynamicScene
	{
		void RenderDebugInfo()
		{
			FUNC(0x0060A700, float, __thiscall, _RenderDebugInfo, DynamicScene*);
			_RenderDebugInfo(this);
		}
	};
}