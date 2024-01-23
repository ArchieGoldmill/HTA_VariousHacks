#pragma once
#include "RefCountedBase.h"
#include "CStr.h"
#include "Game.h"

namespace m3d
{
	struct Object : RefCountedBase
	{
		CStr name;
		bool persistant;
		bool isChildDirty;
		void* parent;
		void* firstChild;
		void* lastChild;
		void* nextSibling;
		void* prevSibling;
		int numChildren;
		void* scriptHandle;

		bool IsKindOf(int cls)
		{
			FUNC(0x006161E0, bool, __thiscall, _IsKindOf, Object*, int);
			return _IsKindOf(this, cls);
		}
	};
}