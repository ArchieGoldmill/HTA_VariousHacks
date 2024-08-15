#pragma once

namespace m3d::cmn
{
	struct XmlNode
	{
		virtual void IBase_dtor_0() = 0;
		virtual void DecRef() = 0;
		virtual void IncRef() = 0;
		virtual void QueryIface() = 0;
		virtual void IsOfType() = 0;
		virtual bool IsEmpty() = 0;
		virtual void HasChildOrAttribute() = 0;
		virtual void GetParent() = 0;
		virtual void GetNextSibling() = 0;
		virtual void GetPrevSibling() = 0;
		virtual void GetFirstChild() = 0;
		virtual void GetLastChild() = 0;
		virtual void AddChild() = 0;
		virtual void AddBeforeChild() = 0;
		virtual void AddAfterChild() = 0;
		virtual void RemoveChild() = 0;
		virtual void GetValue() = 0;
		virtual void SetValue() = 0;
		virtual const char* GetAttribute(const char*) = 0;
		virtual void GetAttributeMbcsSafe() = 0;
		virtual void SetAttribute() = 0;
		virtual void RemoveAttribute() = 0;
		virtual void CreateAttribute() = 0;
		virtual void GetFirstAttribute() = 0;
	};
}