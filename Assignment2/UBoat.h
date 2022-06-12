#pragma once

#include "IDivable.h"
#include "ISailable.h"

#include "Vehicle.h"

namespace assignment2
{
	class UBoat : public Vehicle, public IDivable, public ISailable
	{
	public:
		UBoat();
		virtual ~UBoat();

		virtual void Move();
		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetDiveSpeed() const;
		virtual unsigned int GetSailSpeed() const;

	private:
		enum eUBoat
		{
			MAX_PASSENGERS_COUNT = 50,
			MAX_MOVE_TIME = 2,
			MAX_REST_TIME = 4,
		};
	};
}