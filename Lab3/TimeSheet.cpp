#include "TimeSheet.h"

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries) :
		mName(name),
		mMaxEntries(maxEntries),
		mEntryCount(0),
		mTotalTime(0)
	{
		mEntries = new int[maxEntries];
	}

	TimeSheet::TimeSheet(const TimeSheet& other) :
		mName(other.mName),
		mMaxEntries(other.mMaxEntries),
		mEntryCount(other.mEntryCount),
		mTotalTime(other.mTotalTime)
	{
		delete[] mEntries;
		mEntries = new int[other.mMaxEntries];
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
		mEntryCount = other.mEntryCount;
		mTotalTime = other.mTotalTime;

		delete[] mEntries;
		mEntries = new int[other.mMaxEntries];
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

		return (float)mTotalTime / (float)mEntryCount;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		const float variance = getVariance();
		const float standardDeviation = sqrt(variance);
		return standardDeviation;
	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}


	// private
	float TimeSheet::getVariance() const
	{
		const float average = GetAverageTime();

		float variance = 0.f;

		for (unsigned int i = 0; i < mEntryCount; ++i)
		{
			float time = mEntries[i];
			variance += (time - average) * (time - average);
		}

		variance /= (float)mEntryCount;
		return variance;
	}
}