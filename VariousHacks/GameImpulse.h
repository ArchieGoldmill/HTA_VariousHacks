#pragma once
#include <map>
#include <vector>
#include <set>

#include "Object.h"

namespace m3d
{
	struct IImpulse
	{
		virtual void Dtor() = 0;
	};

	struct KeysSet
	{
		std::set<int> Set;

		bool IsThere(int k)
		{
			FUNC(0x005969B0, bool, __thiscall, _IsThere, KeysSet*, int);
			return _IsThere(this, k);
		}
	};

	struct KeyBindStation
	{
		struct BindKey
		{
			std::vector<m3d::KeysSet> m_keys;
		};

		std::vector<m3d::KeyBindStation::BindKey> m_bindings;
	};

	struct GameImpulse : IImpulse, m3d::Object
	{
		virtual void Dtor() = 0;

		int m_refCount;
		int m_parent;
		bool m_isInited;
		bool m_isBinded;
		bool m_bSuppressEvent;
		std::map<int, m3d::KeyBindStation> m_bindings;
		std::map<int, bool> m_impulseStates;
		std::map<int, bool> m_impulseResetAfterRead;
		m3d::KeysSet CurKeys;
		CStr m_profileFileName;

		bool GetImpulseState(int impId)
		{
			FUNC(0x00597250, bool, __thiscall, _GetImpulseState, GameImpulse*, int);
			return _GetImpulseState(this, impId);
		}
		
		bool GetImpulseStateAndReset(int impId)
		{
			FUNC(0x005946E0, bool, __thiscall, _GetImpulseStateAndReset, GameImpulse*, int);
			return _GetImpulseStateAndReset(this, impId);
		}
	};
}