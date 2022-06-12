#pragma once

#include "Vehicle.h"

namespace assignment2
{
	class DeusExMachina
	{
	public:
		static DeusExMachina* GetInstance();

		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;

	private:
		static DeusExMachina mInstance;

		DeusExMachina();
		virtual ~DeusExMachina();
		DeusExMachina(const DeusExMachina& other) = delete;
		DeusExMachina& operator=(const DeusExMachina& other) = delete;

		enum EDeusExMachina
		{
			MAX_VEHICLES_COUNT = 10,
		};

	private:
		unsigned int mVehiclesCount;
		Vehicle* mVehicles[EDeusExMachina::MAX_VEHICLES_COUNT];
	};
}