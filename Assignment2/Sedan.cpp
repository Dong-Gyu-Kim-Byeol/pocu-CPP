#include <cassert>

#include "Sedan.h"
#include "Trailer.h"

namespace assignment2
{
	Sedan::Sedan() :
		Vehicle(eSedan::MAX_PASSENGERS_COUNT),
		mTrailerOrNull(nullptr)
	{
	}

	Sedan::~Sedan()
	{
		if (mTrailerOrNull != nullptr)
		{
			delete mTrailerOrNull;
			mTrailerOrNull = nullptr;
		}
	}

	Sedan::Sedan(const Sedan& other) :
		Vehicle(other),
		mTrailerOrNull(nullptr)
	{
		if (other.mTrailerOrNull != nullptr)
		{
			const Trailer* newTrailer = new Trailer(*other.mTrailerOrNull);
			mTrailerOrNull = newTrailer;
		}
	}

	Sedan& Sedan::operator=(const Sedan& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		this->Vehicle::operator=(rhs);

		mTrailerOrNull = nullptr;
		if (rhs.mTrailerOrNull != nullptr)
		{
			const Trailer* newTrailer = new Trailer(*rhs.mTrailerOrNull);
			mTrailerOrNull = newTrailer;
		}

		return *this;
	}

	void Sedan::Move()
	{
		if (mTrailerOrNull == nullptr)
		{
			if (mMovedTime >= eSedan::MAX_MOVE_TIME_NONE_TRAILER && mRestedTime >= eSedan::MAX_REST_TIME_NONE_TRAILER)
			{
				mMovedTime = 0;
				mRestedTime = 0;
			}

			if (mMovedTime >= eSedan::MAX_MOVE_TIME_NONE_TRAILER)
			{
				++mRestedTime;
				return;
			}

			assert(mRestedTime == 0);

			mMovedDistance += GetMaxSpeed();
			++mMovedTime;
			return;
		}

		if (mTrailerOrNull != nullptr)
		{
			if (mMovedTime >= eSedan::MAX_MOVE_TIME_TRAILER && mRestedTime >= eSedan::MAX_REST_TIME_TRAILER)
			{
				mMovedTime = 0;
				mRestedTime = 0;
			}

			if (mMovedTime >= eSedan::MAX_MOVE_TIME_TRAILER)
			{
				++mRestedTime;
				return;
			}

			assert(mRestedTime == 0);

			mMovedDistance += GetMaxSpeed();
			++mMovedTime;
			return;
		}
	}

	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		// If x <= 80, speed = 480 
		// If x > 80, speed = 458
		// If x > 160, speed = 400
		// If x > 260, speed = 380
		// If x > 350, speed = 300

		const double weight = static_cast<double>(GetTotalPassengerWeight()) + static_cast<double>(getTrailerWeight());

		double speed = 0.0;
		if (weight > 350)
		{
			speed = 300.0;
		}
		else if (weight > 260)
		{
			speed = 380.0;
		}
		else if (weight > 160)
		{
			speed = 400.0;
		}
		else if (weight > 80)
		{
			speed = 458.0;
		}
		else if (weight <= 80)
		{
			speed = 480.0;
		}

		assert(speed != 0.0);
		return static_cast<unsigned int>(speed);
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		assert(trailer != nullptr);

		if (mTrailerOrNull != nullptr)
		{
			return false;
		}

		mTrailerOrNull = trailer;
		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mTrailerOrNull == nullptr)
		{
			return false;
		}

		delete mTrailerOrNull;
		mTrailerOrNull = nullptr;
		return true;
	}

	unsigned int Sedan::getTrailerWeight() const
	{
		if (mTrailerOrNull == nullptr)
		{
			return 0;
		}

		return mTrailerOrNull->GetWeight();
	}
}