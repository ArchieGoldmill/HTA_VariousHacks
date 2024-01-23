#pragma once
#include "CVector.h"
#include "GeomRepositoryItem.h"

struct DragSlot
{

};

struct DragDropItemsWnd
{
	inline static DragSlot*& DragSlot = *(DragSlot**)0x00A42120;

	int OnMouseButton0(unsigned int state, const PointBase<float>* at)
	{
		FUNC(0x00443840, int, __thiscall, _OnMouseButton0, DragDropItemsWnd*, unsigned int, const PointBase<float>*);
		return _OnMouseButton0(this, state, at);
	}

	void GetItemFromOrigin(ai::GeomRepositoryItem* result, const PointBase<float>* wndPt)
	{
		FUNC(0x0046C670, int, __thiscall, _OnMouseButton0, DragDropItemsWnd*, ai::GeomRepositoryItem * , const PointBase<float>*);
		_OnMouseButton0(this, result, wndPt);
	}
};