#pragma once

#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class RectangleLawn : public Lawn, public IFenceable
	{
	public:
		RectangleLawn(const unsigned int width, const unsigned int height);
		virtual ~RectangleLawn();

		virtual unsigned int GetArea() const override;
		virtual unsigned int GetMinimumFencesCount() const override;
		virtual unsigned int GetFencePrice(eFenceType fenceType) const override;

	private:
		const double mHeight;
		const double mWidth;
	};
}