#pragma once

#include <cassert>
#include <vector>

namespace lab9
{
	template <typename T>
	class CycleQueue
	{
	public:
		CycleQueue(const size_t capacity);
		CycleQueue(const CycleQueue& other) = default;
		CycleQueue& operator=(const CycleQueue& rhs) = default;

		size_t GetSize() const;
		size_t GetCapacity() const;
		bool Enqueue(const T& value);
		T Dequeue();

		~CycleQueue() = default;

	private:
		size_t getArrayCapacity() const;
		size_t calculateNextIndex(const size_t nowIndex) const;

		size_t mCapacity;
		std::vector<T> mArray;
		size_t mSize;
		size_t mFront;
		size_t mEmptyBack;
	};

	template <typename T>
	CycleQueue<T>::CycleQueue(const size_t capacity) :
		mCapacity(capacity),
		mArray(capacity + 1),
		mSize(0),
		mFront(0),
		mEmptyBack(0)
	{
	}

	template <typename T>
	size_t CycleQueue<T>::GetSize() const
	{
		return mSize;
	}

	template <typename T>
	size_t CycleQueue<T>::GetCapacity() const
	{
		return mCapacity;
	}

	template <typename T>
	bool CycleQueue<T>::Enqueue(const T& value)
	{
		if (calculateNextIndex(mEmptyBack) == mFront)
		{
			return false;
		}

		mArray[mEmptyBack] = value;
		mEmptyBack = calculateNextIndex(mEmptyBack);
		++mSize;
		return value;
	}

	template <typename T>
	T CycleQueue<T>::Dequeue()
	{
		assert(mFront != mEmptyBack);

		T value = mArray[mFront];
		mFront = calculateNextIndex(mFront);
		--mSize;

		return value;
	}

	template <typename T>
	size_t CycleQueue<T>::getArrayCapacity() const
	{
		return mArray.capacity();
	}

	template <typename T>
	size_t CycleQueue<T>::calculateNextIndex(const size_t nowIndex) const
	{
		return (nowIndex + 1) % getArrayCapacity();
	}
}