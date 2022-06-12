#include <cassert>

#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina DeusExMachina::mInstance;

	DeusExMachina* DeusExMachina::GetInstance()
	{
		return &mInstance;
	}

	DeusExMachina::DeusExMachina() :
		mVehiclesCount(0),
		mVehicles{ 0, }
	{
	}

	DeusExMachina::~DeusExMachina()
	{
		for (unsigned int i = 0; i < mVehiclesCount; ++i)
		{
			delete mVehicles[i];
			mVehicles[i] = nullptr;
		}
	}

	void DeusExMachina::Travel() const
	{
		for (unsigned int i = 0; i < mVehiclesCount; ++i)
		{
			mVehicles[i]->Move();
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		assert(vehicle != nullptr);

		if (mVehiclesCount >= eDeusExMachina::MAX_VEHICLES_COUNT)
		{
			return false;
		}

		vehicle->ResetMovedDistance();
		mVehicles[mVehiclesCount] = vehicle;

		++mVehiclesCount;
		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (mVehiclesCount == 0 || mVehiclesCount <= i)
		{
			return false;
		}

		delete mVehicles[i];
		mVehicles[i] = nullptr;

		for (; i < mVehiclesCount - 1; ++i)
		{
			mVehicles[i] = mVehicles[i + 1];
			mVehicles[i + 1] = nullptr;
		}

		--mVehiclesCount;
		return true;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (mVehiclesCount == 0)
		{
			return nullptr;
		}

		unsigned int furthestTravelled = 0;
		const Vehicle* furthestVehicle = mVehicles[0];

		for (unsigned int i = 0; i < mVehiclesCount; ++i)
		{
			if (furthestTravelled < mVehicles[i]->GetMovedDistance())
			{
				furthestTravelled = mVehicles[i]->GetMovedDistance();
				furthestVehicle = mVehicles[i];
			}
		}

		return furthestVehicle;
	}
}