#pragma once
#include "GameImpulse.h"
#include "IRenderer.h"

namespace m3d
{
	struct Application
	{
		inline static Application*& Instance = *(Application**)0x00A0A55C;

		BYTE _offset[0x2FC];
		m3d::rend::IRenderer* Renderer;
		BYTE _offset1[0x8AF40];
		IImpulse* Impulse;

		int OneFrame()
		{
			FUNC(0x005A3AD0, int, __thiscall, _OneFrame, Application*);
			return _OneFrame(this);
		}
	};
}