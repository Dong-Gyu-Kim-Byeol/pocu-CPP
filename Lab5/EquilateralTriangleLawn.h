#pragma once

#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class EquilateralTriangleLawn : public Lawn, public IFenceable
	{
	public:
		EquilateralTriangleLawn(const unsigned int width);
		virtual ~EquilateralTriangleLawn();

		virtual unsigned int GetArea() const override;
		virtual unsigned int GetMinimumFencesCount() const override;
		virtual unsigned int GetFencePrice(eFenceType fenceType) const override;

	private:
		const double mWidth;
	};
}