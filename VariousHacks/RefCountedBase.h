#pragma once

namespace m3d
{
	struct RefCountedBase
	{
		int vTable;
		int refCount;
	};
}