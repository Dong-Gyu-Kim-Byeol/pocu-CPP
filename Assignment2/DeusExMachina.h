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
		DeusExMachina(const DeusExMachina& other) = delete;
		virtual DeusExMachina& operator=(const DeusExMachina& other) = delete;
		virtual ~DeusExMachina();		

		enum eDeusExMachina
		{
			MAX_VEHICLES_COUNT = 10,
		};

		unsigned int mVehiclesCount;
		Vehicle* mVehicles[eDeusExMachina::MAX_VEHICLES_COUNT];
	};
}