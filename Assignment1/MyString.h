#pragma once
namespace assignment1
{
	class MyString
	{
		// required
	public:
		MyString(const char* s);
		MyString(const MyString& other);
		~MyString();

		unsigned int GetLength() const;
		const char* GetCString() const;
		void Append(const char* s);
		MyString operator+(const MyString& other) const;
		int IndexOf(const char* s);
		int LastIndexOf(const char* s);
		void Interleave(const char* s);
		bool RemoveAt(unsigned int i);
		void PadLeft(unsigned int totalLength);
		void PadLeft(unsigned int totalLength, const char c);
		void PadRight(unsigned int totalLength);
		void PadRight(unsigned int totalLength, const char c);
		void Reverse();
		bool operator==(const MyString& rhs) const;
		MyString& operator=(const MyString& rhs);
		void ToLower();
		void ToUpper();

	private:
		MyString(char* newCString, unsigned int newLength);
		void init(const char* s);
		void destroy();

	private:
		static unsigned int calculateLength(const char* s);
		static int indexOfRabinKarp(const char* const str, const char* const word);
		static int lastIndexOfRabinKarp(const char* const str, const char* const word);
		static bool isEqual(const char* const s1, const char* const s2);

	private:
		char* mCString;
		unsigned int mLength;
	};
}