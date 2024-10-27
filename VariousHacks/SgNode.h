#pragma once
#include "Object.h"

namespace m3d
{
	struct SgNode : Object
	{
		virtual void Dtor() = 0;
		virtual void Clone() = 0;
		virtual void ReadFromXmlNode() = 0;
		virtual void ReadFromXmlNodeAfterAdd() = 0;
		virtual void WriteToXmlNode() = 0;
		virtual void SetProperty(unsigned int propId, void* prop) = 0;

		void GetProperty(unsigned int propId, void* prop) override
		{
			FUNC(0x0063EB10, void, __thiscall, _GetProperty, m3d::SgNode*, unsigned int propId, void* prop);
			_GetProperty(this, propId, prop);
		}

		void SetRotation(const Quaternion* quat)
		{
			FUNC(0x0040C1B0, void, __thiscall, _SetRotation, m3d::SgNode*, const Quaternion*);
			_SetRotation(this, quat);
		}

		Quaternion* GetRotation()
		{
			FUNC(0x00616D80, Quaternion*, __thiscall, _GetRotation, m3d::SgNode*);
			return _GetRotation(this);
		}
	};
}