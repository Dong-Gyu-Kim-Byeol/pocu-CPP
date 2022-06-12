#include <cassert>
#include <cmath>

#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat() :
		Vehicle(EUBoat::MAX_PASSENGERS_COUNT)
	{
	}

	UBoat::~UBoat()
	{
	}

	void UBoat::Move()
	{
		if (mMovedTime >= EUBoat::MAX_MOVE_TIME && mRestedTime >= EUBoat::MAX_REST_TIME)
		{
			mMovedTime = 0;
			mRestedTime = 0;
		}

		if (mMovedTime >= EUBoat::MAX_MOVE_TIME)
		{
			++mRestedTime;
			return;
		}

		assert(mRestedTime == 0);

		mMovedDistance += GetMaxSpeed();
		++mMovedTime;
	}

	unsigned int UBoat::GetMaxSpeed() const
	{
		return std::max(GetDiveSpeed(), GetSailSpeed());
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		// 500 * log((x + 150)/150) + 30

		const double weight = static_cast<double>(GetTotalPassengerWeight());
		const double speed = 500.0 * std::log10((weight + 150.0) / 150.0) + 30.0;
		return static_cast<unsigned int>(std::round(speed));
	}

	unsigned int UBoat::GetSailSpeed() const
	{
		// MAX((550 - x/10), 200)

		const double weight = static_cast<double>(GetTotalPassengerWeight());
		const double speed = std::max((550.0 - weight / 10.0), 200.0);
		return static_cast<unsigned int>(std::round(speed));
	}
}