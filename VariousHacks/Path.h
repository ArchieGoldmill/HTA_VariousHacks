#pragma once

namespace ai {
	struct Path {
		unsigned int m_size;
		char _offset[0x74];
	};
}

ASSERT_SIZE(ai::Path, 0x78);