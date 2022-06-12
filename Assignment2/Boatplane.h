#pragma once

#include "IDrivable.h"
#include "IFlyable.h"
#include "ISailable.h"

#include "Vehicle.h"

namespace assignment2
{
	class Airplane;
	class Boat;

	class Boatplane : public Vehicle, public IFlyable, public ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		virtual ~Boatplane();

		virtual void Move();
		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetFlySpeed() const;
		virtual unsigned int GetSailSpeed() const;

	private:
		enum EBoatplane
		{
			MAX_MOVE_TIME = 1,
			MAX_REST_TIME = 3,
		};
	};
}