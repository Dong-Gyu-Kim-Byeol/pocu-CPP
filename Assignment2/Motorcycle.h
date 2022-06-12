#pragma once

#include "IDrivable.h"

#include "Vehicle.h"

namespace assignment2
{
	class Motorcycle : public Vehicle, public IDrivable
	{
	public:
		Motorcycle();
		virtual ~Motorcycle();

		virtual void Move();
		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetDriveSpeed() const;

	private:

	private:
		enum EMotorcycle
		{
			MAX_PASSENGERS_COUNT = 2,
			MAX_MOVE_TIME = 5,
			MAX_REST_TIME = 1,
		};
	};
}