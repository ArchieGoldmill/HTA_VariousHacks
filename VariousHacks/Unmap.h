#pragma once
#include <utility>

// For some reason std::map structure does not match what we have in the game, specifically _Myval, _Color and _Isnil are in a different order.

template <typename T1, typename T2>
struct UnmapNode
{
	UnmapNode* _Left;
	UnmapNode* _Parent;
	UnmapNode* _Right;
	std::pair<T1, T2> _Myval;
	char _Color;
	char _Isnil;
};

template <typename T1, typename T2>
struct Unmap
{
	int pad;
	UnmapNode<T1, T2>* _Myhead;
	int _Mysize;
};