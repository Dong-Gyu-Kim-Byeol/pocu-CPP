#pragma once

#include "IFlyable.h"
#include "IDrivable.h"

#include "Vehicle.h"

namespace assignment2
{
	class Boat;
	class Boatplane;

	class Airplane : public Vehicle, public IFlyable, public IDrivable
	{
	public:
		Airplane(unsigned int maxPassengersCount);
		virtual ~Airplane();

		virtual void Move();
		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetFlySpeed() const;
		virtual unsigned int GetDriveSpeed() const;

		Boatplane operator+(Boat& boat);

		static const double EULER_NUMBER;

	private:
		enum EAirplane
		{
			MAX_MOVE_TIME = 1,
			MAX_REST_TIME = 3,
		};

	private:
		Airplane(const Airplane& other) = delete;
		void operator=(const Airplane& rhs) = delete;
	};
}
