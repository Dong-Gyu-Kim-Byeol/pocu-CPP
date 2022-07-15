#pragma once

#include <memory>
#include "CycleQueue.h"

namespace lab9
{
	using namespace std;

	template <typename T>
	class ObjectPool final
	{
	public:
		ObjectPool(const size_t maxPoolSize);
		ObjectPool(const ObjectPool& other) = delete;
		ObjectPool& operator=(const ObjectPool& rhs) = delete;

		~ObjectPool() = default;

		size_t GetFreeObjectCount() const;
		size_t GetMaxFreeObjectCount() const;

		T* Get();
		void Return(T* p);

	private:
		CycleQueue<T*> mCycleQueue;
	};

	template <typename T>
	ObjectPool<T>::ObjectPool(const size_t maxPoolSize) :
		mCycleQueue(maxPoolSize)
	{
	}

	template <typename T>
	size_t ObjectPool<T>::GetFreeObjectCount() const
	{
		return mCycleQueue.Size();
	}

	template <typename T>
	size_t ObjectPool<T>::GetMaxFreeObjectCount() const
	{
		return mCycleQueue.Capacity();
	}

	template <typename T>
	T* ObjectPool<T>::Get()
	{
		if (mCycleQueue.Size() == 0)
		{
			T* newObject = new T();
			return newObject;
		}

		T* front = mCycleQueue.Dequeue();
		return front;
	}

	template <typename T>
	void ObjectPool<T>::Return(T* p)
	{
		if (mCycleQueue.Size() == mCycleQueue.Capacity())
		{
			delete p;
			p = nullptr;
			return;
		}

		mCycleQueue.Enqueue(p);
	}
}

