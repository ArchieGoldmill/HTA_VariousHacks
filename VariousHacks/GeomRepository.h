#pragma once

namespace ai
{
	struct GeomRepository
	{
		void GiveUpThingByObjId(int objId)
		{
			FUNC(0x006CAFA0, void, __thiscall, _OnMouseButton0, GeomRepository*, int);
			_OnMouseButton0(this, objId);
		}
	};
}