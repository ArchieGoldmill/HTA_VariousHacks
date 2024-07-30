#pragma once

namespace m3d
{
	struct RefCountedBase
	{
		virtual void Dtor() = 0;

		int refCount;
	};
}