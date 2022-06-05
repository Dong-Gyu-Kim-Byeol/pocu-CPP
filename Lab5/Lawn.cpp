#include <cassert>
#include <cmath>

#include "Lawn.h"

namespace lab5
{
	const double Lawn::ROLL_AREA = 0.3;

	Lawn::Lawn()
	{
	}

	Lawn::~Lawn()
	{
	}

	//
	// public

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		const double rollCount = GetMinimumSodRollsCount();

		double priceSent = 0.0;
		switch (grassType)
		{
		case lab5::BERMUDA:
			priceSent = rollCount * 800.0 * ROLL_AREA;
			break;
		case lab5::BAHIA:
			priceSent = rollCount * 500.0 * ROLL_AREA;
			break;
		case lab5::BENTGRASS:
			priceSent = rollCount * 300.0 * ROLL_AREA;
			break;
		case lab5::PERENNIAL_RYEGRASS:
			priceSent = rollCount * 250.0 * ROLL_AREA;
			break;
		case lab5::ST_AUGUSTINE:
			priceSent = rollCount * 450.0 * ROLL_AREA;
			break;
		default:
			assert(false);
			break;
		}

		const double price = priceSent / 100.0;
		return price;
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		const double area = GetArea();
		const double rollCount = area / ROLL_AREA;

		return ceil(rollCount);
	}
}
