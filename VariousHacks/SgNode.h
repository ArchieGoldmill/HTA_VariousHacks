#pragma once

namespace m3d
{
	struct SgNode
	{
		virtual void Dtor() = 0;
		virtual void Clone() = 0;
		virtual void ReadFromXmlNode() = 0;
		virtual void ReadFromXmlNodeAfterAdd() = 0;
		virtual void WriteToXmlNode() = 0;
		virtual void SetProperty(unsigned int propId, void* prop) = 0;

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