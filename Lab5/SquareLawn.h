#pragma once

#include "RectangleLawn.h"

namespace lab5
{
	class SquareLawn : public RectangleLawn
	{
	public:
		SquareLawn(const int width);
		virtual ~SquareLawn();
	};
}