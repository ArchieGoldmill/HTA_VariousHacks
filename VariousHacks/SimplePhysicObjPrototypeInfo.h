#pragma once
#include "PhysicObjPrototypeInfo.h"
#include <vector>
#include "CollisionInfo.h"

namespace ai
{
	struct SimplePhysicObjPrototypeInfo : PhysicObjPrototypeInfo
	{
		std::vector<ai::CollisionInfo> m_collisionInfos;
		bool m_bCollisionTrimeshAllowed;
		int m_geomType;// ai::GeomType
		CStr m_engineModelName;
		CVector m_size;
		float m_radius;
		float m_massValue;
	};
}