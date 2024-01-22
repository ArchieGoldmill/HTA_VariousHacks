#pragma once
#include <set>

#include "PhysicBody.h"
#include "SgNode.h"
#include "Numeric.h"
#include "NumericInRangeRegenerating.h"
#include "DecalData.h"

namespace ai
{
	struct VehiclePart : PhysicBody
	{
		struct ModelPart
		{
			float maxHealth;
			float health;
			float jadedEffect;
		};

		struct LoadDecalData
		{
			int node;
			m3d::DecalData dd;
			int meshNum;
		};

		int m_SplashEffect;
		bool m_MakeSplash;
		std::map<int, m3d::SgNode*> m_decals;
		ai::Numeric<float> m_price;
		ai::NumericInRangeRegenerating<float> m_durability;
		CStr m_partName;
		int m_durabilityCoeffsForDamageTypes[4];
		CStr m_blowEffectName;
		std::set<int> m_suppressedLPs;
		std::vector<ai::VehiclePart::ModelPart> m_modelParts;
		CVector m_lastHitPos;
		int m_passToAnotherMapData;
		std::vector<ai::VehiclePart::LoadDecalData> m_loadDecalsData;
		int m_ownerCompoundPart;
	};
}