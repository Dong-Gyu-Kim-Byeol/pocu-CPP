#include <cassert>
#include <cmath>

#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Vehicle.h"
#include "Person.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount) :
		Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	void Boat::Move()
	{
		if (mMovedTime >= eBoat::MAX_MOVE_TIME && mRestedTime >= eBoat::MAX_REST_TIME)
		{
			mMovedTime = 0;
			mRestedTime = 0;
		}

		if (mMovedTime >= eBoat::MAX_MOVE_TIME)
		{
			++mRestedTime;
			return;
		}

		assert(mRestedTime == 0);

		mMovedDistance += GetMaxSpeed();
		++mMovedTime;
	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	unsigned int Boat::GetSailSpeed() const
	{
		// MAX((800 - 10x), 20)

		const double weight = static_cast<double>(GetTotalPassengerWeight());
		const double speed = std::max(800.0 - 10.0 * weight, 20.0);
		return static_cast<double>(std::round(speed));
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		Boatplane bp(this->GetMaxPassengersCount() + plane.GetMaxPassengersCount());

		while (true)
		{
			const Person* person = plane.GetPassenger(0);
			if (person == nullptr)
			{
				break;
			}

			const Person* newPerson = new Person(*person);
			bp.AddPassenger(newPerson);

			plane.RemovePassenger(0);
		}

		while (true)
		{
			const Person* person = this->GetPassenger(0);
			if (person == nullptr)
			{
				break;
			}

			const Person* newPerson = new Person(*person);
			bp.AddPassenger(newPerson);

			this->RemovePassenger(0);
		}		

		return bp;
	}
}