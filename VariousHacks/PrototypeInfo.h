#pragma once
#include "CStr.h"

namespace ai
{
	struct PrototypeInfo
	{
		virtual void Dtor() = 0;

		CStr m_className;
		CStr m_prototypeName;
		int m_prototypeId;
		int m_resourceId;
		bool m_bIsUpdating;
		bool m_bVisibleInEncyclopedia;
		bool m_bApplyAffixes;
		float m_price;
		bool m_bIsAbstract;
		CStr m_parentPrototypeName;
		int m_protoClassObject;
	};
}