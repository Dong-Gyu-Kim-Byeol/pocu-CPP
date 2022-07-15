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

		~ObjectPool();

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
	ObjectPool<T>::~ObjectPool()
	{
		while (mCycleQueue.GetSize() != 0)
		{
			T* object = mCycleQueue.Dequeue();
			delete object;
			object = nullptr;
		}
	}

	template <typename T>
	size_t ObjectPool<T>::GetFreeObjectCount() const
	{
		return mCycleQueue.GetSize();
	}

	template <typename T>
	size_t ObjectPool<T>::GetMaxFreeObjectCount() const
	{
		return mCycleQueue.GetCapacity();
	}

	template <typename T>
	T* ObjectPool<T>::Get()
	{
		if (mCycleQueue.GetSize() == 0)
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
		if (mCycleQueue.GetSize() == mCycleQueue.GetCapacity())
		{
			delete p;
			p = nullptr;
			return;
		}

		mCycleQueue.Enqueue(p);
	}
}

