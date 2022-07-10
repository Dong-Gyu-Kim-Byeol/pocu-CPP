#pragma once

#include <queue>
#include <limits>
#include <cmath>

namespace assignment3
{
	template <typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		SmartQueue(const SmartQueue& other) = default;
		SmartQueue& operator=(const SmartQueue& rhs) = default;
		virtual ~SmartQueue() = default;

		unsigned int GetCount() const;
		void Enqueue(const T number);
		T Dequeue();
		T Peek() const;

		T GetMax() const;
		T GetMin() const;
		T GetSum() const;
		double GetAverage() const;
		double GetVariance() const;
		double GetStandardDeviation() const;

	private:
		std::queue<T> mNumQueue;

		T mSum;
		T mPowSum;
	};

	template <typename T>
	SmartQueue<T>::SmartQueue() :
		mSum(0),
		mPowSum(0)
	{
	}

	template <typename T>
	unsigned int SmartQueue<T>::GetCount() const
	{
		return static_cast<unsigned int>(mNumQueue.size());
	}

	template <typename T>
	void SmartQueue<T>::Enqueue(const T number)
	{
		mNumQueue.emplace(number);

		mSum += number;
		mPowSum += number * number;
	}

	template <typename T>
	T SmartQueue<T>::Dequeue()
	{
		const T number = mNumQueue.front();

		mNumQueue.pop();

		mSum -= number;
		mPowSum -= number * number;

		return number;
	}

	template <typename T>
	T SmartQueue<T>::Peek() const
	{
		const T number = mNumQueue.front();
		return number;
	}

	template <typename T>
	T SmartQueue<T>::GetMax() const
	{
		std::queue<T> queue(mNumQueue);
		T max = std::numeric_limits<T>::lowest();
		while (!queue.empty())
		{
			const T number = queue.front();

			if (max < number)
			{
				max = number;
			}

			queue.pop();
		}

		return max;
	}

	template <typename T>
	T SmartQueue<T>::GetMin() const
	{
		std::queue<T> queue(mNumQueue);
		T min = std::numeric_limits<T>::max();
		while (!queue.empty())
		{
			const T number = queue.front();

			if (min > number)
			{
				min = number;
			}

			queue.pop();
		}

		return min;
	}

	template <typename T>
	T SmartQueue<T>::GetSum() const
	{
		return mSum;
	}

	template <typename T>
	double SmartQueue<T>::GetAverage() const
	{
		if (GetCount() == 0)
		{
			return 0.0;
		}

		const double average = static_cast<double>(mSum) / static_cast<double>(GetCount());
		return average;
	}

	template <typename T>
	double SmartQueue<T>::GetVariance() const
	{
		if (GetCount() == 0)
		{
			return 0.0;
		}

		const double average = GetAverage();
		const double variance = static_cast<double>(mPowSum) / static_cast<double>(GetCount()) - average * average;
		return variance;
	}

	template <typename T>
	double SmartQueue<T>::GetStandardDeviation() const
	{
		const double variance = GetVariance();
		const double standardDeviation = std::sqrt(variance);
		return standardDeviation;
	}
}