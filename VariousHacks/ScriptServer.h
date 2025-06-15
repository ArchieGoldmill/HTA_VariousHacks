#pragma once

namespace m3d
{
	struct ScriptServer
	{
		void Execute(const char* str, const char* bufName)
		{
			FUNC(0x006203C0, void, __thiscall, _Execute, ScriptServer*, const char*, const char*);
			_Execute(this, str, bufName);
		}
	};
}