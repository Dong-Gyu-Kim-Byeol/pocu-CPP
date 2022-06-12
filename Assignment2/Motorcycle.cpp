#include <cassert>
#include <cmath>

#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle() :
		Vehicle(eMotorcycle::MAX_PASSENGERS_COUNT)
	{
	}

	Motorcycle::~Motorcycle()
	{
	}

	void Motorcycle::Move()
	{
		if (mMovedTime >= eMotorcycle::MAX_MOVE_TIME && mRestedTime >= eMotorcycle::MAX_REST_TIME)
		{
			mMovedTime = 0;
			mRestedTime = 0;
		}

		if (mMovedTime >= eMotorcycle::MAX_MOVE_TIME)
		{
			++mRestedTime;
			return;
		}

		assert(mRestedTime == 0);

		mMovedDistance += GetMaxSpeed();
		++mMovedTime;
	}

	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		// MAX((-(x/15)^3 + 2x + 400), 0)

		const double weight = static_cast<double>(GetTotalPassengerWeight());
		
		double speed = std::max((std::pow(-(weight / 15.0), 3.0) + 2.0 * weight + 400.0), 0.0);
		speed = std::round(speed);

		unsigned int iSpeed = static_cast<double>(speed);
		return iSpeed;
	}
}