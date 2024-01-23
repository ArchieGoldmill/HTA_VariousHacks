#pragma once
#include "ComplexPhysicObj.h"
#include "IzvratRepository.h"

namespace ai
{
	struct Vehicle : ComplexPhysicObj
	{
		BYTE _offset[0x28C];
		IzvratRepository* Repository;
	};
}