#pragma once
#include "Obj.h"
#include "Quaternion.h"

namespace ai
{
	struct PhysicObj : ai::Obj
	{
		int m_postActionFlags;
		Quaternion m_postRotation;
		CVector m_postPosition;
		int m_physicBehaviorFlags;
		CVector m_massCenter;
		int m_spaceId;
		bool m_bIsSpaceOwner;
		void* m_body;
		void* m_intersectionObstacle;
		int m_lookSphere;
		int m_boundSphere;
		int m_physicState;
		int m_bIsUpdatingByODE;
		int m_enabledCellsCount;
		bool m_bBodyEnabledLastFrame;
		int SkinNumber;
		int m_timeFromLastCollisionEffect;

		CVector* GetDirection(CVector* result)
		{
			FUNC(0x005FA360, CVector*, __thiscall, _GetDirection, PhysicObj*, CVector*);
			return _GetDirection(this, result);
		}
	};
}