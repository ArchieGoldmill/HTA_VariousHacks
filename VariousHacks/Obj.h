#pragma once
#include <map>

#include "Object.h"
#include "Modifier.h"

namespace ai
{
	struct Obj : m3d::Object
	{
		struct EventRecipientInfo
		{
			int m_eventId;
			std::vector<int> m_objIds;
		};

		int objId;
		int updatingObjId;
		bool isUpdating;
		bool mustBeUpdating;
		int flags;
		int m_actionID;
		int m_prevActionID;
		float m_timeOut;
		bool m_bNeedPostLoad;
		bool m_bMustCreateVisualPart;
		bool m_bPassedToAnotherMap;
		int m_belong;
		int m_parentId;
		int m_parentRepository;
		int m_LastDamageSource;
		bool m_bIsAlreadySaved;
		int m_hierarchyType;
		int PrototypeId;
		std::map<int, ai::Obj*> m_allChildren;
		std::vector<int> m_appliedPrefixIds;
		std::vector<int> m_appliedSuffixIds;
		bool m_bAffixesWasApplied;
		std::vector<ai::Modifier> m_modifiers;
		std::vector<ai::Obj::EventRecipientInfo> m_eventRecipients;
	};
}