#pragma once

#include <stack>
#include <limits>
#include <cmath>

namespace assignment3
{
	template <typename T>
	class SmartStack
	{
	public:
		SmartStack();
		SmartStack(const SmartStack& other) = default;
		SmartStack& operator=(const SmartStack& rhs) = default;
		virtual ~SmartStack() = default;

		unsigned int GetCount() const;
		void Push(const T number);
		T Pop();
		T Peek() const;

		T GetMax() const;
		T GetMin() const;
		T GetSum() const;
		double GetAverage() const;
		double GetVariance() const;
		double GetStandardDeviation() const;

	private:
		std::stack<T> mNumStack;
		std::stack<T> mMaxStack;
		std::stack<T> mMinStack;

		T mSum;
		T mPowSum;
	};

	template <typename T>
	SmartStack<T>::SmartStack() :
		mSum(0),
		mPowSum(0)
	{
	}

	template <typename T>
	unsigned int SmartStack<T>::GetCount() const
	{
		return static_cast<unsigned int>(mNumStack.size());
	}

	template <typename T>
	void SmartStack<T>::Push(const T number)
	{
		if (GetMax() <= number)
		{
			mMaxStack.emplace(number);
		}

		if (GetMin() >= number)
		{
			mMinStack.emplace(number);
		}

		mNumStack.emplace(number);

		mSum += number;
		mPowSum += number * number;
	}

	template <typename T>
	T SmartStack<T>::Pop()
	{
		const T number = mNumStack.top();

		if (mMaxStack.size() > 0 && GetMax() == number)
		{
			mMaxStack.pop();
		}

		if (mMinStack.size() > 0 && GetMin() == number)
		{
			mMinStack.pop();
		}

		mNumStack.pop();

		mSum -= number;
		mPowSum -= number * number;

		return number;
	}

	template <typename T>
	T SmartStack<T>::Peek() const
	{
		const T number = mNumStack.top();
		return number;
	}

	template <typename T>
	T SmartStack<T>::GetMax() const
	{
		if (mMaxStack.size() == 0)
		{
			const T max = std::numeric_limits<T>::lowest();
			return max;
		}

		return mMaxStack.top();

		/*std::stack<T> stack(mNumStack);
		T max = std::numeric_limits<T>::lowest();
		while (!stack.empty())
		{
			const T number = stack.top();

			if (max < number)
			{
				max = number;
			}

			stack.pop();
		}

		return max;*/
	}

	template <typename T>
	T SmartStack<T>::GetMin() const
	{
		if (mMinStack.size() == 0)
		{
			return std::numeric_limits<T>::max();
		}

		return mMinStack.top();

		/*std::stack<T> stack(mNumStack);
		T min = std::numeric_limits<T>::max();
		while (!stack.empty())
		{
			const T number = stack.top();

			if (min > number)
			{
				min = number;
			}

			stack.pop();
		}

		return min;*/
	}

	template <typename T>
	T SmartStack<T>::GetSum() const
	{
		return mSum;
	}

	template <typename T>
	double SmartStack<T>::GetAverage() const
	{
		if (GetCount() == 0)
		{
			return 0.0;
		}

		const double average = static_cast<double>(mSum) / static_cast<double>(GetCount());
		return average;
	}

	template <typename T>
	double SmartStack<T>::GetVariance() const
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
	double SmartStack<T>::GetStandardDeviation() const
	{
		const double variance = GetVariance();
		const double standardDeviation = std::sqrt(variance);
		return standardDeviation;
	}
}