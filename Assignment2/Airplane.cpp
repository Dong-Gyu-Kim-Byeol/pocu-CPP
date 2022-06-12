#include <cassert>
#include <cmath>

#include "Person.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

namespace assignment2
{
	const double Airplane::EULER_NUMBER = 2.71828182845904523536028747135266249775724709369995;

	Airplane::Airplane(unsigned int maxPassengersCount) :
		Vehicle(maxPassengersCount)
	{
	}

	Airplane::~Airplane()
	{
	}

	void Airplane::Move()
	{
		if (mMovedTime >= eAirplane::MAX_MOVE_TIME && mRestedTime >= eAirplane::MAX_REST_TIME)
		{
			mMovedTime = 0;
			mRestedTime = 0;
		}

		if (mMovedTime >= eAirplane::MAX_MOVE_TIME)
		{
			++mRestedTime;
			return;
		}

		assert(mRestedTime == 0);

		mMovedDistance += GetMaxSpeed();
		++mMovedTime;
	}

	unsigned int Airplane::GetMaxSpeed() const
	{
		return std::max(GetFlySpeed(), GetDriveSpeed());
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		// 200 * EULER_NUMBER ^ ((-x + 800) / 500)

		const double weight = static_cast<double>(GetTotalPassengerWeight());
		const double speed = std::round(200.0 * std::pow(EULER_NUMBER, ((-weight + 800.0) / 500.0)));
		return static_cast<unsigned int>(speed);
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		// 4 * e^((-x + 400) / 70)

		const double weight = static_cast<double>(GetTotalPassengerWeight());
		const double speed = std::round(4.0 * std::pow(EULER_NUMBER, ((-weight + 400.0) / 70.0)));
		return static_cast<unsigned int>(speed);
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane bp(this->GetMaxPassengersCount() + boat.GetMaxPassengersCount());

		while (true)
		{
			const Person* person = this->GetPassenger(0);
			if (person == nullptr)
			{
				break;
			}

			const Person* newPerson = new Person(*person);
			if (!bp.AddPassenger(newPerson))
			{
				delete newPerson;
				newPerson = nullptr;
			}

			this->RemovePassenger(0);
		}

		while (true)
		{
			const Person* person = boat.GetPassenger(0);
			if (person == nullptr)
			{
				break;
			}

			const Person* newPerson = new Person(*person);
			if (!bp.AddPassenger(newPerson))
			{
				delete newPerson;
				newPerson = nullptr;
			}

			boat.RemovePassenger(0);
		}

		return bp;
	}
}