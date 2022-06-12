#pragma once

namespace assignment2
{
	class Person;

	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		Vehicle(const Vehicle& other);
		Vehicle& operator=(const Vehicle& rhs);
		virtual ~Vehicle();		

		virtual void Move() = 0;
		virtual unsigned int GetMaxSpeed() const = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		unsigned int GetTotalPassengerWeight() const;

		unsigned int GetMovedDistance() const;
		void ResetMovedDistance();

	protected:
		enum EVehicle
		{
			MAX_PASSENGERS_COUNT = 100
		};

		unsigned int mMovedDistance;
		unsigned int mMovedTime;
		unsigned int mRestedTime;

	private:
		unsigned int mMaxPassengersCount;
		unsigned int mPassengersCount;
		const Person* mPassengers[EVehicle::MAX_PASSENGERS_COUNT];

		unsigned int mTotalPassengerWeight;
	};
}