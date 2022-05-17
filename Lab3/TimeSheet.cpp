#include <cassert>

#include "TimeSheet.h"

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries) :
		mName(name),
		mMaxEntries(maxEntries),
		mEntryCount(0),
		mTotalTime(0),

		mEntries(new int[maxEntries])
	{
	}

	TimeSheet::TimeSheet(const TimeSheet& other) :
		mName(other.mName),
		mMaxEntries(other.mMaxEntries),
		mEntryCount(0),
		mTotalTime(0),

		mEntries(new int[other.mMaxEntries])
	{
		setEntries(other.mEntryCount, other.mEntries);
	}

	TimeSheet::~TimeSheet()
	{
		delete[] mEntries;
		mEntries = nullptr;
	}

	void TimeSheet::operator=(const TimeSheet& other)
	{
		mName = other.mName;
		mMaxEntries = other.mMaxEntries;
		mEntryCount = 0;
		mTotalTime = 0;

		delete[] mEntries;
		mEntries = new int[other.mMaxEntries];
		setEntries(other.mEntryCount, other.mEntries);
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (mEntryCount >= mMaxEntries)
		{
			return;
		}

		if (TimeSheet::MIN_TIME_IN_HOUR <= timeInHours && timeInHours <= TimeSheet::MAX_TIME_IN_HOUR)
		{
			mEntries[mEntryCount++] = timeInHours;
			mTotalTime += timeInHours;
			return;
		}
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (mEntryCount <= index)
		{
			return -1;
		}

		return mEntries[index];
	}

	int TimeSheet::GetTotalTime() const
	{
		return mTotalTime;
	}

	float TimeSheet::GetAverageTime() const
	{
		if (0 == mEntryCount)
		{
			return 0.f;
		}

		return static_cast<float>(mTotalTime) / static_cast<float>(mEntryCount);
	}

	float TimeSheet::GetStandardDeviation() const
	{
		if (0 == mEntryCount)
		{
			return 0.f;
		}

		const float variance = getVariance();
		const float standardDeviation = sqrtf(variance);
		return standardDeviation;
	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}


	// private
	void TimeSheet::setEntries(const unsigned int otherEntryCount, const int* const otherEntries)
	{
		assert(otherEntryCount <= mMaxEntries);

		mEntryCount = otherEntryCount;
		mTotalTime = 0;

		for (unsigned int i = 0; i < otherEntryCount; ++i)
		{
			mEntries[i] = otherEntries[i];
			mTotalTime += otherEntries[i];
		}
	}

	float TimeSheet::getVariance() const
	{
		const float average = GetAverageTime();

		float variance = 0.f;

		for (unsigned int i = 0; i < mEntryCount; ++i)
		{
			float time = mEntries[i];
			variance += (time - average) * (time - average);
		}

		variance /= static_cast<float>(mEntryCount);
		return variance;
	}
}