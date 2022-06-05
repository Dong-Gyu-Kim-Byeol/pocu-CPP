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
		const double area = GetArea();

		double priceSent = 0.0;
		switch (grassType)
		{
		case lab5::BERMUDA:
			priceSent = area * 800.0;
			break;
		case lab5::BAHIA:
			priceSent = area * 500.0;
			break;
		case lab5::BENTGRASS:
			priceSent = area * 300.0;
			break;
		case lab5::PERENNIAL_RYEGRASS:
			priceSent = area * 250.0;
			break;
		case lab5::ST_AUGUSTINE:
			priceSent = area * 450.0;
			break;
		default:
			assert(false);
			break;
		}

		const double price = priceSent / 100.0;
		return static_cast<unsigned int>(round(price));
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		const double area = GetArea();
		const double rollCount = area / ROLL_AREA;

		return static_cast<unsigned int>(ceil(rollCount));
	}
}
