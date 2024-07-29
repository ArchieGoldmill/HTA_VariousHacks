#pragma once

namespace m3d::rend
{
	enum FillMode
	{
		M3DFILL_POINT = 0,
		M3DFILL_WIREFRAME = 1,
		M3DFILL_SOLID = 2
	};

	struct IRenderer
	{
		virtual void Dtor() = 0;
		virtual void DecRef() = 0;
		virtual void IncRef() = 0;
		virtual void QueryIface() = 0;
		virtual void Create() = 0;
		virtual void CreateDevice() = 0;
		virtual void SwitchDisplayModes() = 0;
		virtual void Reset() = 0;
		virtual void gap20() = 0;
		virtual void PushBlend() = 0;
		virtual void PopBlend() = 0;
		virtual void SetBlend() = 0;
		virtual void gap30() = 0;
		virtual void PushZbState() = 0;
		virtual void PopZbState() = 0;
		virtual void SetZbState() = 0;
		virtual void gap40() = 0;
		virtual void PushCull() = 0;
		virtual void PopCull() = 0;
		virtual void SetCull() = 0;
		virtual void gap50() = 0;
		virtual void PushZFunc() = 0;
		virtual void PopZFunc() = 0;
		virtual void SetZFunc() = 0;
		virtual void gap60() = 0;
		virtual void PushLighting() = 0;
		virtual void PopLighting() = 0;
		virtual void SetLighting() = 0;
		virtual void gap70() = 0;
		virtual void PushAmbient() = 0;
		virtual void PopAmbient() = 0;
		virtual void SetAmbient() = 0;
		virtual void gap80() = 0;
		virtual void PushFog() = 0;
		virtual void PopFog() = 0;
		virtual void SetFog() = 0;
		virtual void gap90() = 0;
		virtual void PushFogColor() = 0;
		virtual void PopFogColor() = 0;
		virtual void SetFogColor() = 0;
		virtual void gapA0() = 0;
		virtual void PushFogMode() = 0;
		virtual void PopFogMode() = 0;
		virtual void SetFogMode() = 0;
		virtual void gapB0() = 0;
		virtual void PushFogStart() = 0;
		virtual void PopFogStart() = 0;
		virtual void SetFogStart() = 0;
		virtual void gapC0() = 0;
		virtual void PushFogEnd() = 0;
		virtual void PopFogEnd() = 0;
		virtual void SetFogEnd() = 0;
		virtual void  gapD0(FillMode fillMode) = 0;
		virtual void __fastcall PushFillMode(FillMode fillMode) = 0;
		virtual void  PopFillMode() = 0;
		virtual void __thiscall SetFillMode(FillMode fillMode) = 0;
	};
}