#pragma once
#include <vector>

#include "Obj.h"
#include "dMass.h"
#include "GeomTransform.h"
#include "CollisionInfo.h"
#include "Game.h"

namespace ai
{
	struct PhysicBody : Obj
	{
		CStr m_modelname;
		dMass mass;
		std::vector<ai::GeomTransform*> m_pGeoms;
		int m_mU;
		int m_Node;
		int m_cfgNum;
		std::vector<ai::CollisionInfo> m_collisionInfos;
		bool m_bCollisionTrimeshAllowed;
		Obj* OwnerPhysicObj;
		bool m_bNeedToRelinkNode;
		int m_animAction;
		int m_effectAction;
		bool m_bAnimationIsStopped;
		int m_loadedAnimTime;

		void SetNodeRelativeRotation(const Quaternion* q)
		{
			FUNC(0x00619D90, void, __thiscall, _SetNodeRelativeRotation, ai::PhysicBody*, const Quaternion*);
			_SetNodeRelativeRotation(this, q);
		}

		void GetNodeRelativeRotation(Quaternion* result)
		{
			FUNC(0x00619C20, void, __thiscall, _GetNodeRelativeRotation, ai::PhysicBody*, const Quaternion*);
			_GetNodeRelativeRotation(this, result);
		}
	};
}