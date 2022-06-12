#include <cassert>

#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount) :
		mMaxPassengersCount(maxPassengersCount),
		mPassengersCount(0),
		mPassengers{ 0, },
		mTotalPassengerWeight(0),

		mMovedDistance(0),
		mMovedTime(0),
		mRestedTime(0)
	{
		assert(maxPassengersCount <= eVehicle::MAX_PASSENGERS_COUNT);
	}

	Vehicle::~Vehicle()
	{
		for (unsigned int i = 0; i < mPassengersCount; ++i)
		{
			delete mPassengers[i];
			mPassengers[i] = nullptr;
		}
	}

	Vehicle::Vehicle(const Vehicle& other) :
		mMaxPassengersCount(other.mMaxPassengersCount),
		mPassengersCount(0),
		mPassengers{ 0, },
		mTotalPassengerWeight(0),

		mMovedDistance(0),
		mMovedTime(0),
		mRestedTime(0)
	{
		for (unsigned int i = 0; i < other.mPassengersCount; ++i)
		{
			const Person* newPerson = new Person(*other.mPassengers[i]);
			this->AddPassenger(newPerson);
		}
	}

	Vehicle& Vehicle::operator=(const Vehicle& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		this->mMaxPassengersCount = rhs.mMaxPassengersCount;
		this->mPassengersCount = 0;
		this->mTotalPassengerWeight = 0;

		this->mMovedDistance = 0;
		this->mMovedTime = 0;
		this->mRestedTime = 0;

		for (unsigned int i = 0; i < rhs.mPassengersCount; ++i)
		{
			const Person* newPerson = new Person(*rhs.mPassengers[i]);
			this->AddPassenger(newPerson);
		}

		return *this;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (GetPassengersCount() >= mMaxPassengersCount)
		{
			return false;
		}

		mTotalPassengerWeight += person->GetWeight();

		mPassengers[mPassengersCount] = person;
		++mPassengersCount;
		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (mPassengersCount == 0 || mPassengersCount <= i)
		{
			return false;
		}

		mTotalPassengerWeight -= mPassengers[i]->GetWeight();

		delete mPassengers[i];
		mPassengers[i] = nullptr;

		for (; i < mPassengersCount - 1; ++i)
		{
			mPassengers[i] = mPassengers[i + 1];
			mPassengers[i + 1] = nullptr;
		}

		--mPassengersCount;
		return true;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (GetPassengersCount() == 0 || GetPassengersCount() <= i)
		{
			return nullptr;
		}

		return mPassengers[i];
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mPassengersCount;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengersCount;
	}

	unsigned int Vehicle::GetTotalPassengerWeight() const
	{
		return mTotalPassengerWeight;
	}

	unsigned int Vehicle::GetMovedDistance() const
	{
		return mMovedDistance;
	}

	void Vehicle::ResetMovedDistance()
	{
		mMovedDistance = 0;
		mMovedTime = 0;
		mRestedTime = 0;
	}
}