#pragma once

namespace ai
{
	struct Geom
	{
		struct CellAabb
		{
			float x0;
			float z0;
			float x1;
			float z1;
		};

		int vTable;
		int m_geomId;
		ai::Geom::CellAabb m_curAabb;
	};
}