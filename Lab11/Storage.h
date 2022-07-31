#pragma once

#include <memory>
#include <vector>

namespace lab11
{
	using namespace std;

	template<typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);

		Storage(const Storage& other);
		void operator=(const Storage& rhs);

		Storage(Storage&& other);
		void operator=(Storage&& rhs);

		~Storage() = default;

		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;

	private:
		unique_ptr<T[]> mArray;
		unsigned int mSize;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length) :
		mSize(length),
		mArray(make_unique<T[]>(length))
	{
		memset(mArray.get(), 0, sizeof(T) * mSize);
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue) :
		mSize(length),
		mArray(make_unique<T[]>(length))
	{
		for (unsigned int i = 0; i < mSize; ++i)
		{
			mArray[i] = initialValue;
		}
	}

	template<typename T>
	Storage<T>::Storage(const Storage& other) :
		mSize(other.mSize),
		mArray(make_unique<T[]>(other.mSize))
	{
		for (unsigned int i = 0; i < mSize; ++i)
		{
			mArray[i] = other.mArray[i];
		}
	}

	template<typename T>
	void Storage<T>::operator=(const Storage& rhs)
	{
		if (this == &rhs)
		{
			return;
		}

		mArray = nullptr;

		mSize = rhs.mSize;
		mArray = make_unique<T[]>(rhs.mSize);
		for (unsigned int i = 0; i < mSize; ++i)
		{
			mArray[i] = rhs.mArray[i];
		}
	}

	template<typename T>
	Storage<T>::Storage(Storage&& other) :
		mSize(other.mSize),
		mArray(std::move(other.mArray))
	{
		other.mSize = 0;
		other.mArray = nullptr;
	}

	template<typename T>
	void Storage<T>::operator=(Storage&& rhs)
	{
		if (this == &rhs)
		{
			return;
		}

		mSize = rhs.mSize;
		mArray = std::move(rhs.mArray);

		rhs.mSize = 0;
		rhs.mArray = nullptr;
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index < mSize)
		{
			mArray[index] = data;
			return true;
		}

		return false;
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		return mArray;
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mSize;
	}
}