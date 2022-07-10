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
		return 0;
	}

	template <typename T>
	void SmartQueue<T>::Enqueue(const T number)
	{
	}

	template <typename T>
	T SmartQueue<T>::Dequeue()
	{
		return 0;
	}

	template <typename T>
	T SmartQueue<T>::Peek() const
	{
		return 0;
	}

	template <typename T>
	T SmartQueue<T>::GetMax() const
	{
		return 0;
	}

	template <typename T>
	T SmartQueue<T>::GetMin() const
	{
		return 0;
	}

	template <typename T>
	T SmartQueue<T>::GetSum() const
	{
		return 0;
	}

	template <typename T>
	double SmartQueue<T>::GetAverage() const
	{
		return 0;
	}

	template <typename T>
	double SmartQueue<T>::GetVariance() const
	{
		return 0;
	}

	template <typename T>
	double SmartQueue<T>::GetStandardDeviation() const
	{
		return 0;
	}
}