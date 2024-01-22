#pragma once
#include "RefCountedBase.h"
#include "CStr.h"

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
	};
}