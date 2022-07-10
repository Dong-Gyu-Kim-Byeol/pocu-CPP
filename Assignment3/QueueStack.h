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
		T mSum;
	};

	template <typename T>
	QueueStack<T>::QueueStack(const unsigned int maxStackSize) :
		mMaxStackSize(maxStackSize),
		mSum(0)
	{
	}

	template <typename T>
	unsigned int QueueStack<T>::GetCount() const
	{
		return 0;
	}

	template <typename T>
	unsigned int QueueStack<T>::GetStackCount() const
	{
		return 0;
	}

	template <typename T>
	void QueueStack<T>::Enqueue(const T number)
	{
		
	}

	template <typename T>
	T QueueStack<T>::Dequeue()
	{
		return 0;
	}

	template <typename T>
	T QueueStack<T>::Peek() const
	{
		return 0;
	}

	template <typename T>
	T QueueStack<T>::GetMax() const
	{
		return 0;
	}

	template <typename T>
	T QueueStack<T>::GetMin() const
	{
		return 0;
	}

	template <typename T>
	T QueueStack<T>::GetSum() const
	{
		return 0;
	}

	template <typename T>
	double QueueStack<T>::GetAverage() const
	{
		return 0;
	}
}