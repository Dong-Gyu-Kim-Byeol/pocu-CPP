#include <cmath>

#include "CircleLawn.h"

namespace lab5
{
	const double CircleLawn::PI = 3.14;

	CircleLawn::CircleLawn(const unsigned int radius) :
		mRadius(radius)
	{
	}

	//
	// public virtual

	CircleLawn::~CircleLawn()
	{
	}

	unsigned int CircleLawn::GetArea() const
	{
		const double area = static_cast<double>(mRadius) * static_cast<double>(mRadius) * PI;
		return static_cast<unsigned int>(ceil(area));
	}
}