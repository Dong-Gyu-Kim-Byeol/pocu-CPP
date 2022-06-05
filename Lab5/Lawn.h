#pragma once

#include "eGrassType.h"

namespace lab5
{
	class Lawn
	{
	public:
		Lawn();
		virtual ~Lawn();

		unsigned int GetGrassPrice(eGrassType grassType) const;
		unsigned int GetMinimumSodRollsCount() const;
				
		virtual unsigned int GetArea() const = 0;

	private:
		static const double ROLL_AREA;
	};
}

