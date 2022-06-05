#include <cassert>
#include <cmath>

#include "EquilateralTriangleLawn.h"

namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn(const unsigned int width) :
		Lawn(),
		mWidth(width)
	{
	}

	EquilateralTriangleLawn::~EquilateralTriangleLawn()
	{
	}

	// 
	// public virtual

	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		const double area = static_cast<double>(mWidth) * static_cast<double>(mWidth) * sqrt(2.0) / 4.0;
		return ceil(area);
	}

	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		const double round = 3.0 * mWidth;
		const double rollCount = round / IFenceable::FENCE_WIDTH;

		return ceil(rollCount);
	}

	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		const double fenceCount = GetMinimumFencesCount();

		double price = 0.0;
		switch (fenceType)
		{
		case lab5::RED_CEDAR:
			price = fenceCount * 6.0 * IFenceable::FENCE_WIDTH;
			break;
		case lab5::SPRUCE:
			price = fenceCount * 7.0 * IFenceable::FENCE_WIDTH;
			break;
		default:
			assert(false);
			break;
		}

		return round(price);
	}
}