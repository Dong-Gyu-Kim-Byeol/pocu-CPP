#include <cassert>
#include <cmath>

#include "Airplane.h"
#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount):
		Vehicle(maxPassengersCount)
	{
	}

	Boatplane::~Boatplane()
	{
	}

	void Boatplane::Move()
	{
		if (mMovedTime >= EBoatplane::MAX_MOVE_TIME && mRestedTime >= EBoatplane::MAX_REST_TIME)
		{
			mMovedTime = 0;
			mRestedTime = 0;
		}

		if (mMovedTime >= EBoatplane::MAX_MOVE_TIME)
		{
			++mRestedTime;
			return;
		}

		assert(mRestedTime == 0);

		mMovedDistance += GetMaxSpeed();
		++mMovedTime;
	}

	unsigned int Boatplane::GetMaxSpeed() const
	{
		return std::max(GetFlySpeed(), GetSailSpeed());
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		// 150 * e ^ ((-x + 500) / 300)

		const double weight = static_cast<double>(GetTotalPassengerWeight());
		const double speed = 150.0 * std::pow(Airplane::EULER_NUMBER, ((-weight + 500.0) / 300.0));
		return static_cast<unsigned int>(std::round(speed));
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		// MAX((800 - 1.7x), 20)

		const double weight = static_cast<double>(GetTotalPassengerWeight());
		const double speed = std::max(800.0 - 1.7 * weight, 20.0);
		return static_cast<double>(std::round(speed));
	}
}