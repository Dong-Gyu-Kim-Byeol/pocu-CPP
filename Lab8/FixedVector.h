#pragma once

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
		const T& Get(const size_t index) const;
		T& operator[](const size_t index);
		int GetIndex(const T& t) const;
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		T mArray[N];
		size_t mSize;
	};

	template <typename T, size_t N>
	FixedVector<T, N>::FixedVector() :
		mSize(0)
	{
		memset(mArray, 0, sizeof(mArray));
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
			if (!(mArray[i] == t))
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
	const T& FixedVector<T, N>::Get(const size_t index) const
	{
		return mArray[index];
	}

	template <typename T, size_t N>
	T& FixedVector<T, N>::operator[](const size_t index)
	{
		return mArray[index];
	}

	template <typename T, size_t N>
	int FixedVector<T, N>::GetIndex(const T& t) const
	{
		for (size_t i = 0; i < mSize; ++i)
		{
			if (!(mArray[i] == t))
			{
				continue;
			}

			return static_cast<int>(i);
		}

		return -1;
	}

	template <typename T, size_t N>
	size_t FixedVector<T, N>::GetSize() const
	{
		return mSize;
	}

	template <typename T, size_t N>
	size_t FixedVector<T, N>::GetCapacity() const
	{
		return N;
	}
}
