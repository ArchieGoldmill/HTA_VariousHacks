#pragma once
#include "RefCountedBase.h"
#include "CStr.h"
#include "Game.h"

namespace m3d
{
	struct Object : RefCountedBase
	{
		virtual void Dtor() = 0;
		virtual void Clone() = 0;
		virtual void ReadFromXmlNode() = 0;
		virtual void ReadFromXmlNodeAfterAdd() = 0;
		virtual void WriteToXmlNode() = 0;
		virtual void SetProperty(unsigned int propId, void* prop) = 0;
		virtual void GetProperty(unsigned int propId, void* prop) = 0;

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