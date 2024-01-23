#pragma once
#include "CVector.h"

namespace ai
{
	struct GeomRepositoryItem
	{
		int m_resourceId;
		int ObjId;
		int m_amount;
		int m_repositoryItemType;
		int m_parentRepository;
		PointBase<int> m_origin;

		bool IsValid()
		{
			FUNC(0x006CCC40, bool, __thiscall, _OnMouseButton0, GeomRepositoryItem*);
			return _OnMouseButton0(this);
		}

		ai::Obj* GetObj()
		{
			FUNC(0x006CD0F0, ai::Obj*, __thiscall, _GetObj, GeomRepositoryItem*);
			return _GetObj(this);
		}
	};
}