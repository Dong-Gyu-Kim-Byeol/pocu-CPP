#pragma once

#include <queue>
#include <stack>

namespace assignment3
{
	template <typename T>
	class QueueStack
	{
	public:
		QueueStack(const unsigned int maxStackSize);
		QueueStack(const QueueStack& other) = default;
		QueueStack& operator=(const QueueStack& rhs) = default;
		virtual ~QueueStack() = default;

		unsigned int GetCount() const;
		unsigned int GetStackCount() const;
		void Enqueue(const T number);
		T Dequeue();
		T Peek() const;

		T GetMax() const;
		T GetMin() const;
		T GetSum() const;
		double GetAverage() const;

	private:
		unsigned int mMaxStackSize;
		std::queue<std::stack<T>> mQueueStack;

		double mSum;
	};

	template <typename T>
	QueueStack<T>::QueueStack(const unsigned int maxStackSize) :
		mMaxStackSize(maxStackSize),
		mSum(0.0)
	{
	}

	template <typename T>
	unsigned int QueueStack<T>::GetCount() const
	{
		if (GetStackCount() == 0)
		{
			return 0;
		}

		if (GetStackCount() == 1)
		{
			return static_cast<unsigned int>(mQueueStack.back().size());
		}

		return (GetStackCount() - 2) * mMaxStackSize
			+ static_cast<unsigned int>(mQueueStack.front().size())
			+ static_cast<unsigned int>(mQueueStack.back().size());
	}

	template <typename T>
	unsigned int QueueStack<T>::GetStackCount() const
	{
		return static_cast<unsigned int>(mQueueStack.size());
	}

	template <typename T>
	void QueueStack<T>::Enqueue(const T number)
	{
		if (mMaxStackSize == 0)
		{
			return;
		}

		if (mQueueStack.empty())
		{
			mQueueStack.emplace(std::stack<T>());
		}

		std::stack<T>* backStack = &mQueueStack.back();
		if (backStack->size() >= mMaxStackSize)
		{
			mQueueStack.emplace(std::stack<T>());
			backStack = &mQueueStack.back();
		}

		backStack->emplace(number);

		mSum += static_cast<double>(number);
	}

	template <typename T>
	T QueueStack<T>::Dequeue()
	{
		std::stack<T>* frontStack = &mQueueStack.front();
		const T number = frontStack->top();

		frontStack->pop();
		if (frontStack->size() == 0)
		{
			mQueueStack.pop();
			frontStack = nullptr;
		}

		mSum -= static_cast<double>(number);

		return number;
	}

	template <typename T>
	T QueueStack<T>::Peek() const
	{
		const std::stack<T>* frontStack = &mQueueStack.front();
		const T number = frontStack->top();

		return number;
	}

	template <typename T>
	T QueueStack<T>::GetMax() const
	{
		std::queue<std::stack<T>> queueStack(mQueueStack);
		T max = std::numeric_limits<T>::lowest();
		while (!queueStack.empty())
		{
			std::stack<T>& stack = queueStack.front();

			while (!stack.empty())
			{
				const T number = stack.top();

				if (max < number)
				{
					max = number;
				}

				stack.pop();
			}

			queueStack.pop();
		}

		return max;
	}

	template <typename T>
	T QueueStack<T>::GetMin() const
	{
		std::queue<std::stack<T>> queueStack(mQueueStack);
		T min = std::numeric_limits<T>::max();
		while (!queueStack.empty())
		{
			std::stack<T>& stack = queueStack.front();

			while (!stack.empty())
			{
				const T number = stack.top();

				if (min > number)
				{
					min = number;
				}
				stack.pop();
			}

			queueStack.pop();
		}

		return min;
	}

	template <typename T>
	T QueueStack<T>::GetSum() const
	{
		return static_cast<double>(mSum);
	}

	template <typename T>
	double QueueStack<T>::GetAverage() const
	{
		if (GetCount() == 0)
		{
			return 0.0;
		}

		const double average = mSum / static_cast<double>(GetCount());
		return average;
	}
}