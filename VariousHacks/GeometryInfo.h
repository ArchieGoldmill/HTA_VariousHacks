#pragma once

namespace m3d
{
	struct GeometryInfo
	{
		int mesh;
		int numIndices;
		int indices;
		int vertices;
		int vertexStride;
		int transform;
		int oldMesh;
	};
}