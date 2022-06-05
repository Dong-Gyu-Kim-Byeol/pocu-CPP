#pragma once

#include "Lawn.h"

namespace lab5
{
	class CircleLawn : public Lawn
	{
	public:
		CircleLawn(const unsigned int radius);

		virtual ~CircleLawn();
		virtual unsigned int GetArea() const override;

	private:
		const double mRadius;

		static const double PI;
	};
}