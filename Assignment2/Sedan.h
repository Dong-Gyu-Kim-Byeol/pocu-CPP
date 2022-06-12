#pragma once

#include "IDrivable.h"

#include "Vehicle.h"

namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable
	{
	public:
		Sedan();
		Sedan(const Sedan& other);
		Sedan& operator=(const Sedan& rhs);
		virtual ~Sedan();

		virtual void Move();
		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetDriveSpeed() const;

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();

	private:
		unsigned int getTrailerWeight() const;

	private:
		enum eSedan
		{
			MAX_PASSENGERS_COUNT = 4,
			MAX_MOVE_TIME_NONE_TRAILER = 5,
			MAX_REST_TIME_NONE_TRAILER = 1,
			MAX_MOVE_TIME_TRAILER = 5,
			MAX_REST_TIME_TRAILER = 2,
		};

	private:
		const Trailer* mTrailerOrNull;

	};
}