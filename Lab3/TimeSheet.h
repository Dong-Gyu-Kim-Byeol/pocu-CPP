#pragma once
#include <string>

namespace lab3
{
	class TimeSheet
	{
	public:
		TimeSheet(const char* name, unsigned int maxEntries);
		TimeSheet(const TimeSheet& other);

		~TimeSheet();

		void operator=(const TimeSheet& other);

		void AddTime(int timeInHours);
		int GetTimeEntry(unsigned int index) const;
		int GetTotalTime() const;
		float GetAverageTime() const;
		float GetStandardDeviation() const;
		const std::string& GetName() const;

	private:
		void setEntries(const unsigned int otherEntryCount, const int* const otherEntries);
		float getVariance() const;

	private:
		std::string mName;

		unsigned int mMaxEntries;
		unsigned int mEntryCount;
		int mTotalTime;

		int* mEntries;

		static const int MIN_TIME_IN_HOUR = 1;
		static const int MAX_TIME_IN_HOUR = 10;
	};
}
