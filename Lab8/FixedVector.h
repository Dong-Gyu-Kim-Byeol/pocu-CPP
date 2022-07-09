#pragma once

#include <memory>

namespace lab8
{
	template <typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		FixedVector(const FixedVector& other) = default;
		FixedVector& operator=(const FixedVector& rhs) = default;
		virtual ~FixedVector() = default;

		bool Add(const T& t);
		bool Remove(const T& t);
		const T& Get(const size_t index);
		T& operator[](const size_t index);
		size_t GetIndex(const T& t);
		size_t GetSize();
		size_t GetCapacity();

	private:
		T mArray[N];
		size_t mSize;
	};

	template <typename T, size_t N>
	FixedVector<T, N>::FixedVector() :
		mSize(0)
	{
	}

	template <typename T, size_t N>
	bool FixedVector<T, N>::Add(const T& t)
	{
		if (mSize >= N)
		{
			return false;
		}

		mArray[mSize] = t;
		++mSize;
		return true;
	}

	template <typename T, size_t N>
	bool FixedVector<T, N>::Remove(const T& t)
	{
		for (size_t i = 0; i < mSize; ++i)
		{
			if (mArray[i] != t)
			{
				continue;
			}

			if (mSize >= 1)
			{
				for (size_t r = i; r < mSize - 1; ++r)
				{
					mArray[r] = mArray[r + 1];
				}
			}

			--mSize;
			return true;
		}

		return false;
	}

	template <typename T, size_t N>
	const T& FixedVector<T, N>::Get(const size_t index)
	{
		return mArray[index];
	}

	template <typename T, size_t N>
	T& FixedVector<T, N>::operator[](const size_t index)
	{
		return mArray[index];
	}

	template <typename T, size_t N>
	size_t FixedVector<T, N>::GetIndex(const T& t)
	{
		for (size_t i = 0; i < mSize; ++i)
		{
			if (mArray[i] != t)
			{
				continue;
			}

			return i;
		}

		return -1;
	}

	template <typename T, size_t N>
	size_t FixedVector<T, N>::GetSize()
	{
		return mSize;
	}

	template <typename T, size_t N>
	size_t FixedVector<T, N>::GetCapacity()
	{
		return N;
	}
}
