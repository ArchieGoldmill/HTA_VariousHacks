#pragma once
#include <vector>

#include "Object.h"
#include "Obj.h"

namespace ai
{
	struct ObjContainer : m3d::Object
	{
		struct Node
		{
			int m_id;
			int m_prevId;
			int m_nextId;
			Obj* m_value;
			bool m_isValid;
			int m_totalObjects;
		};

		struct InnerContainer
		{
			std::vector<ai::ObjContainer::Node> Records;
			std::vector<int> m_freePlaces;
			int m_size;
			int m_firstNodeId;
			int m_lastNodeId;
		};

		inline static ObjContainer*& Instance = *(ObjContainer**)0x00A12E98;

		ai::ObjContainer::InnerContainer AllObjects;
	};
}