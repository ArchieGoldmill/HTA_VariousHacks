#pragma once
#include "Geom.h"

namespace ai
{
	struct GeomTransform : Geom
	{
		int m_innerGeom;
	};
}