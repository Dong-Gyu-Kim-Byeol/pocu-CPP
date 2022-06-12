#pragma once

#include "ISailable.h"

#include "Vehicle.h"

namespace assignment2
{
	class Airplane;
	class Boatplane;

	class Boat : public Vehicle, public ISailable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		virtual ~Boat();

		virtual void Move();
		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetSailSpeed() const;

		Boatplane operator+(Airplane& plane);

	private:
		enum EBoat
		{
			MAX_MOVE_TIME = 2,
			MAX_REST_TIME = 1,
		};
	};
}