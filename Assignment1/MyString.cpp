#include "MyString.h"

#include <cassert>
#include <memory>

namespace assignment1
{
	// required public
	MyString::MyString(const char* s) :
		mLength(0),
		mCString(nullptr)
	{
		init(s);
	}

	MyString::MyString(const MyString& other) :
		mLength(0),
		mCString(nullptr)
	{
		init(other.GetCString());
	}

	MyString::~MyString()
	{
		destroy();
	}

	unsigned int MyString::GetLength() const
	{
		return mLength;
	}

	const char* MyString::GetCString() const
	{
		return mCString;
	}

	void MyString::Append(const char* s)
	{
		const unsigned int preLength = mLength;
		const char* preCString = mCString;
		mCString = nullptr;

		mLength += calculateLength(s);
		mCString = new char[mLength + 1];

		memcpy(mCString, preCString, preLength);
		memcpy(mCString + preLength, s, mLength - preLength);
		mCString[mLength] = '\0';

		delete[] preCString;
		preCString = nullptr;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		const unsigned int newLength = GetLength() + other.GetLength();
		char* const newCString = new char[newLength + 1];

		memcpy(newCString, GetCString(), GetLength());
		memcpy(newCString + GetLength(), other.GetCString(), other.GetLength());
		newCString[newLength] = '\0';

		return MyString(newCString, newLength);
	}

	int MyString::IndexOf(const char* s)
	{
		return indexOfRabinKarp(GetCString(), s);
	}

	int MyString::LastIndexOf(const char* s)
	{
		return lastIndexOfRabinKarp(GetCString(), s);;
	}

	void MyString::Interleave(const char* s)
	{
		const unsigned int preLength = mLength;
		const char* preCString = mCString;
		mCString = nullptr;

		mLength += calculateLength(s);
		mCString = new char[mLength + 1];

		const char* pPreCString = preCString;
		const char* pS = s;
		for (unsigned int i = 0; i < mLength; )
		{
			if ('\0' != *pPreCString)
			{
				mCString[i] = *pPreCString;

				++pPreCString;
				++i;
			}

			if ('\0' != *pS)
			{
				mCString[i] = *pS;

				++pS;
				++i;
			}
		}
		mCString[mLength] = '\0';
		pPreCString = nullptr;
		pS = nullptr;

		delete[] preCString;
		preCString = nullptr;
	}

	bool MyString::RemoveAt(unsigned int i)
	{
		if (mLength > 0 && mLength <= i)
		{
			return false;
		}

		for (unsigned int start = i; start < mLength - 1; ++start)
		{
			mCString[start] = mCString[start + 1];
		}
		mLength -= 1;
		mCString[mLength] = '\0';

		return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		PadLeft(totalLength, ' ');
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		if (totalLength <= mLength)
		{
			return;
		}

		const unsigned int preLength = mLength;
		const char* preCString = mCString;
		mCString = nullptr;

		mLength = totalLength;
		mCString = new char[mLength + 1];

		memset(mCString, c, totalLength - preLength);
		memcpy(mCString + totalLength - preLength, preCString, preLength);
		mCString[mLength] = '\0';

		delete[] preCString;
		preCString = nullptr;
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		PadRight(totalLength, ' ');
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		if (totalLength <= mLength)
		{
			return;
		}

		const unsigned int preLength = mLength;
		const char* preCString = mCString;
		mCString = nullptr;

		mLength = totalLength;
		mCString = new char[mLength + 1];

		memcpy(mCString, preCString, preLength);
		memset(mCString + preLength, c, totalLength - preLength);

		mCString[mLength] = '\0';

		delete[] preCString;
		preCString = nullptr;
	}

	void MyString::Reverse()
	{
		unsigned int left = 0;
		unsigned int right = GetLength() - 1;

		while (left < right)
		{
			const char cLeft = mCString[left];
			mCString[left] = mCString[right];
			mCString[right] = cLeft;

			++left;
			--right;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		if (this == &rhs)
		{
			return true;
		}

		if (GetLength() != rhs.GetLength())
		{
			return false;
		}

		if (isEqual(GetCString(), rhs.GetCString()))
		{
			return true;
		}

		return false;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		destroy();
		init(rhs.GetCString());

		return *this;
	}

	void MyString::ToLower()
	{
		const char LOW_FLAG_MASK = 'a' - 'A';
		char* pmCString = mCString;

		while ('\0' != *pmCString)
		{
			if ('A' <= *pmCString && *pmCString <= 'Z')
			{
				*pmCString = *pmCString | LOW_FLAG_MASK;
			}


			++pmCString;
		}
		pmCString = nullptr;
	}

	void MyString::ToUpper()
	{
		const char UP_FLAG_MASK = ~('a' - 'A');
		char* pmCString = mCString;

		while ('\0' != *pmCString)
		{
			if ('a' <= *pmCString && *pmCString <= 'z')
			{
				*pmCString = *pmCString & UP_FLAG_MASK;
			}

			++pmCString;
		}
		pmCString = nullptr;
	}


	// private
	MyString::MyString(char* newCString, unsigned int newLength) :
		mLength(newLength),
		mCString(newCString)
	{
	}

	void MyString::init(const char* s)
	{
		// setLength
		{
			mLength = calculateLength(s);
		}

		// setCString
		{
			mCString = new char[GetLength() + 1];

			for (unsigned int i = 0; i < GetLength(); ++i)
			{
				mCString[i] = s[i];
			}

			mCString[GetLength()] = '\0';
		}
	}

	void MyString::destroy()
	{
		mLength = 0;

		delete[] mCString;
		mCString = nullptr;
	}


	// static private
	unsigned int MyString::calculateLength(const char* s)
	{
		const char* p = s;

		if ('\0' == *p)
		{
			return 0;
		}

		while ('\0' != *p)
		{
			++p;
		}

		unsigned int length = p - s;
		p = nullptr;

		assert(0 != length);
		return length;
	}

	int MyString::indexOfRabinKarp(const char* const str, const char* const word)
	{
		const unsigned int MUL = 256;
		const unsigned int MOD_PRIME = 101;

		unsigned int strHash = 0;
		unsigned int wordHash = 0;
		unsigned int lastModMul = 1;

		unsigned int wordLength = 0;

		assert(str != NULL);
		assert(word != NULL);

		if ('\0' == *word)
		{
			return 0;
		}

		// make hash
		{
			const char* pStr = str;
			const char* pWord = word;

			while (*pWord != '\0')
			{
				if (*pStr == '\0')
				{
					return -1;
				}

				strHash *= MUL;
				strHash %= MOD_PRIME;
				strHash += *pStr;
				strHash %= MOD_PRIME;

				wordHash *= MUL;
				wordHash %= MOD_PRIME;
				wordHash += *pWord;
				wordHash %= MOD_PRIME;

				if (pWord != word)
				{
					lastModMul *= MUL;
					lastModMul %= MOD_PRIME;
				}

				++pStr;
				++pWord;
			}

			wordLength = pWord - word;
			pStr = nullptr;
			pWord = nullptr;
		}

		// compare string
		{
			const char* pStrFirst = str;

			while (1)
			{
				if (strHash == wordHash)
				{
					const char* pStr = pStrFirst;
					const char* pWord = word;

					while (*pWord != '\0' && *pStr == *pWord)
					{
						++pStr;
						++pWord;
					}

					if (*pWord == '\0')
					{
						return pStrFirst - str;
					}

					pStr = nullptr;
					pWord = nullptr;
				}

				if (*(pStrFirst + wordLength) == '\0')
				{
					break;
				}

				strHash += MOD_PRIME;
				strHash -= (*pStrFirst * lastModMul) % MOD_PRIME;
				strHash %= MOD_PRIME;

				strHash *= MUL;
				strHash %= MOD_PRIME;

				strHash += *(pStrFirst + wordLength);
				strHash %= MOD_PRIME;

				++pStrFirst;
			}

			assert(*(pStrFirst + wordLength) == '\0');
			pStrFirst = nullptr;

			return -1;
		}
	}

	int MyString::lastIndexOfRabinKarp(const char* const str, const char* const word)
	{
		const unsigned int MUL = 256;
		const unsigned int MOD_PRIME = 101;

		unsigned int strHash = 0;
		unsigned int wordHash = 0;
		unsigned int lastModMul = 1;

		unsigned int wordLength = 0;

		assert(str != NULL);
		assert(word != NULL);

		if ('\0' == *word)
		{
			return 0;
		}

		// make hash
		{
			const char* pStr = str;
			const char* pWord = word;

			while (*pWord != '\0')
			{
				if (*pStr == '\0')
				{
					return -1;
				}

				strHash *= MUL;
				strHash %= MOD_PRIME;
				strHash += *pStr;
				strHash %= MOD_PRIME;

				wordHash *= MUL;
				wordHash %= MOD_PRIME;
				wordHash += *pWord;
				wordHash %= MOD_PRIME;

				if (pWord != word)
				{
					lastModMul *= MUL;
					lastModMul %= MOD_PRIME;
				}

				++pStr;
				++pWord;
			}

			wordLength = pWord - word;
			pStr = nullptr;
			pWord = nullptr;
		}

		// compare string
		{
			int retIndex = -1;
			const char* pStrFirst = str;

			while (1)
			{
				if (strHash == wordHash)
				{
					const char* pStr = pStrFirst;
					const char* pWord = word;

					while (*pWord != '\0' && *pStr == *pWord)
					{
						++pStr;
						++pWord;
					}

					if (*pWord == '\0')
					{
						retIndex = pStrFirst - str;
					}

					pStr = nullptr;
					pWord = nullptr;
				}

				if (*(pStrFirst + wordLength) == '\0')
				{
					break;
				}

				strHash += MOD_PRIME;
				strHash -= (*pStrFirst * lastModMul) % MOD_PRIME;
				strHash %= MOD_PRIME;

				strHash *= MUL;
				strHash %= MOD_PRIME;

				strHash += *(pStrFirst + wordLength);
				strHash %= MOD_PRIME;

				++pStrFirst;
			}

			assert(*(pStrFirst + wordLength) == '\0');
			pStrFirst = nullptr;

			if (-1 != retIndex)
			{
				return retIndex;
			}

			return -1;
		}
	}

	bool MyString::isEqual(const char* const s1, const char* const s2)
	{
		const char* pS1 = s1;
		const char* pS2 = s2;

		while ('\0' != *pS1 && *pS1 == *pS2)
		{
			++pS1;
			++pS2;
		}

		if ('\0' == *pS1 && '\0' == *pS2)
		{
			return true;
		}

		pS1 = nullptr;
		pS2 = nullptr;

		return false;
	}
}