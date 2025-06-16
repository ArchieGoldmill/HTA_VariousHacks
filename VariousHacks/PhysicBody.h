#pragma once
#include <vector>

#include "Obj.h"
#include "dMass.h"
#include "GeomTransform.h"
#include "CollisionInfo.h"
#include "Game.h"
#include "SgNode.h"
#include "PhysicObj.h"
#include "ActionType.h"

namespace ai
{
	struct PhysicBody : Obj
	{
		virtual void Dtor() = 0;

		CStr m_modelname;
		dMass mass;
		std::vector<ai::GeomTransform*> m_pGeoms;
		int m_mU;
		m3d::SgNode* Node;
		int m_cfgNum;
		std::vector<ai::CollisionInfo> m_collisionInfos;
		bool m_bCollisionTrimeshAllowed;
		PhysicObj* OwnerPhysicObj;
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

		void SetEffectActions(std::vector<ActionType>* Actions)
		{
			FUNC(0x0061D180, void, __thiscall, _SetEffectActions, ai::PhysicBody*, std::vector<ActionType>*);
			_SetEffectActions(this, Actions);
		}

		void SetNodeAction(ActionType action, bool forceRestartAction)
		{
			FUNC(0x0061C450, void, __thiscall, _SetEffectActions, ai::PhysicBody*, ActionType, bool);
			_SetEffectActions(this, action, forceRestartAction);
		}

		void SetNodeAnimAction(ActionType action, bool forceRestartAction)
		{
			FUNC(0x0061C5B0, void, __thiscall, _SetNodeAnimAction, ai::PhysicBody*, ActionType, bool);
			_SetNodeAnimAction(this, action, forceRestartAction);
		}

		void SetAnimationStopped(bool bStopped)
		{
			FUNC(0x0061CD30, void, __thiscall, _SetAnimationStopped, ai::PhysicBody*, bool);
			_SetAnimationStopped(this, bStopped);
		}
	};
}