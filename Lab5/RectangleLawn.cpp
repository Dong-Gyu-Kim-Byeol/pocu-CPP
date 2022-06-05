#include <cassert>
#include <cmath>

#include "RectangleLawn.h"

namespace lab5
{
	RectangleLawn::RectangleLawn(const unsigned int width, const unsigned int height) :
		Lawn(),
		mWidth(width),
		mHeight(height)
	{
	}

	RectangleLawn::~RectangleLawn()
	{
	}

	// 
	// public virtual

	unsigned int RectangleLawn::GetArea() const
	{
		const double area = static_cast<double>(mHeight) * static_cast<double>(mWidth);
		return ceil(area);
	}

	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		const double round = 2.0 * mWidth + 2.0 * mHeight;
		const double rollCount = round / IFenceable::FENCE_WIDTH;

		return ceil(rollCount);
	}

	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
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