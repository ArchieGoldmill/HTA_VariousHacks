#pragma once
#include "CVector.h"
#include "Quaternion.h"

namespace ai
{
	struct CollisionInfo
	{
		int m_geomType;
		CVector m_relTranslation;
		Quaternion m_relRotation;
		CVector m_size;
		float m_radius;
		void* m_trimeshVertices;
		int m_numTrimeshVertices;
		void* m_trimeshIndices;
		int m_numTrimeshIndices;
	};
}