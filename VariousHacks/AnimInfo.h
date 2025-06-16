#pragma once

namespace m3d
{
	struct AnimInfo
	{
		BYTE m_offset[0x18];
		bool m_Empty;
		BYTE m_offset2[3 + 4 + 4];
		void* m_curAnimation;
	};
}

ASSERT_SIZE(m3d::AnimInfo, 0x28);