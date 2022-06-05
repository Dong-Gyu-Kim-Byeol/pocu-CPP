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
		const double area = mRadius * mRadius * PI;
		return ceil(area);
	}
}