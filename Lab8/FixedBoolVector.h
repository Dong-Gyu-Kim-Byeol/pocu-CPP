#pragma once

#include "FixedVector.h"
#include <typeinfo>

namespace lab8
{
	template <size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();
		FixedVector(const FixedVector& other) = default;
		FixedVector& operator=(const FixedVector& rhs) = default;
		virtual ~FixedVector() = default;

		bool Add(const bool b);
		bool Remove(const bool b);
		bool Get(const size_t index);
		bool operator[](const size_t index);
		size_t GetIndex(const bool b);
		size_t GetSize();
		size_t GetCapacity();

	private:
		size_t getArraySize();
		size_t getArrayIndex(const size_t index);
		size_t getBitIndex(const size_t index);

		bool getBit(const size_t index);
		void setBit(const size_t index, const bool b);

		enum
		{
			SLOT_BIT_SIZE = sizeof(uint32_t) * 8,
			CAPACITY = (N / SLOT_BIT_SIZE) + (N % SLOT_BIT_SIZE == 0 ? 0 : 1),
		};
		uint32_t mArray[CAPACITY];
		size_t mSize;

	};

	template <size_t N>
	FixedVector<bool, N>::FixedVector() :
		mArray{ 0, },
		mSize(0)
	{
	}

	template <size_t N>
	bool FixedVector<bool, N>::Add(const bool b)
	{
		if (mSize >= N)
		{
			return false;
		}

		setBit(mSize, b);
		++mSize;
		return true;
	}

	template <size_t N>
	bool FixedVector<bool, N>::Remove(const bool b)
	{
		// const size_t arraySize = getArraySize();
		for (size_t i = 0; i < mSize; ++i)
		{
			const bool bBit = getBit(i);
			if (b != bBit)
			{
				continue;
			}

			if (mSize >= 1)
			{
				for (size_t r = i; r < mSize - 1; ++r)
				{
					const bool bNextRBit = getBit(r + 1);
					setBit(r, bNextRBit);
				}
			}

			--mSize;
			return true;
		}

		return false;
	}

	template <size_t N>
	bool FixedVector<bool, N>::Get(const size_t index)
	{
		return getBit(index);
	}

	template <size_t N>
	bool FixedVector<bool, N>::operator[](const size_t index)
	{
		return getBit(index);
	}

	template <size_t N>
	size_t FixedVector<bool, N>::GetIndex(const bool b)
	{
		for (size_t i = 0; i < mSize; ++i)
		{
			const bool bBit = getBit(i);
			if (b != bBit)
			{
				continue;
			}

			return i;
		}

		return -1;
	}

	template <size_t N>
	size_t FixedVector<bool, N>::GetSize()
	{
		return mSize;
	}

	template <size_t N>
	size_t FixedVector<bool, N>::GetCapacity()
	{
		return N;
	}

	template <size_t N>
	size_t FixedVector<bool, N>::getArrayIndex(const size_t index)
	{
		const size_t arrayIndex = index / SLOT_BIT_SIZE;
		return arrayIndex;
	}

	template <size_t N>
	size_t FixedVector<bool, N>::getArraySize()
	{
		const size_t arraySize = (mSize / SLOT_BIT_SIZE) + (mSize % SLOT_BIT_SIZE == 0 ? 0 : 1);
		return arraySize;
	}

	template <size_t N>
	size_t FixedVector<bool, N>::getBitIndex(const size_t index)
	{
		const size_t arrayIndex = index % SLOT_BIT_SIZE;
		return arrayIndex;
	}

	template <size_t N>
	bool FixedVector<bool, N>::getBit(const size_t index)
	{
		const size_t arrayIndex = getArrayIndex(index);
		const size_t bitIndex = getBitIndex(index);

		const uint32_t val = mArray[arrayIndex] & 1 << bitIndex;
		const bool bBit = val == 0 ? false : true;
		return bBit;
	}

	template <size_t N>
	void FixedVector<bool, N>::setBit(const size_t index, const bool b)
	{
		size_t arrayIndex = getArrayIndex(index);
		size_t bitIndex = getBitIndex(index);

		if (b)
		{
			mArray[arrayIndex] = mArray[arrayIndex] | 1 << bitIndex;
		}
		else
		{
			mArray[arrayIndex] = mArray[arrayIndex] & ~(1 << bitIndex);
		}
	}
}
