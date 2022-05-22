#include "MyString.h"

#include <cassert>
#include <string>

using namespace assignment1;

int main()
{
	// 여기에 중단점을 설정해서 b 값을 살펴보거나
	// 아래와 같이 assert() 함수를 써보세요
	// assert(s == s2);	// #include <cassert>이 필요

	{
		MyString s("Hello");
		const unsigned int length = s.GetLength(); // 길이는 5
		assert(5 == length);
	}

	{
		MyString s("Hello");
		s.Append(" World"); // s는 "Hello World"가 됨

		assert(strcmp(s.GetCString(), "Hello World") == 0);
		const unsigned int length = s.GetLength();
		assert(11 == length);
	}

	{
		MyString s1("Hello");
		MyString s2(" World");

		MyString s3 = s1 + s2; // s3는 "Hello World"가 되며, s1와 s2는 여전히 "Hello"와 " World"임

		assert(strcmp(s1.GetCString(), "Hello") == 0);
		unsigned int length = s1.GetLength();
		assert(5 == length);

		assert(strcmp(s2.GetCString(), " World") == 0);
		length = s2.GetLength();
		assert(6 == length);

		assert(strcmp(s3.GetCString(), "Hello World") == 0);
		length = s3.GetLength();
		assert(11 == length);
	}

	{
		MyString s1("Hello");

		int i = s1.IndexOf("ell"); // i는 1
		assert(1 == i);

		int j = s1.IndexOf("l"); // j는 2
		assert(2 == j);

		int z = s1.IndexOf("This"); // z는 -1
		assert(-1 == z);
	}

	{
		MyString s1("Hello");

		int i = s1.LastIndexOf("ell"); // i는 1
		assert(1 == i);

		int j = s1.LastIndexOf("l"); // j는 3
		assert(3 == j);

		int z = s1.LastIndexOf("This"); // z는 -1
		assert(-1 == z);
	}

	{
		MyString s1("Hello");
		s1.Interleave(" World"); // s1은 "H eWlolrold"

		assert(strcmp(s1.GetCString(), "H eWlolrold") == 0);
		unsigned int length = s1.GetLength();
		assert(11 == length);
	}

	{
		MyString s("Hello");

		bool b1 = s.RemoveAt(0); // s는 "ello", b1은 true
		assert(true == b1);
		assert(strcmp(s.GetCString(), "ello") == 0);
		unsigned int length = s.GetLength();
		assert(4 == length);

		bool b2 = s.RemoveAt(2); // s는 "elo", b2은 true
		assert(true == b2);
		assert(strcmp(s.GetCString(), "elo") == 0);
		length = s.GetLength();
		assert(3 == length);

		bool b3 = s.RemoveAt(4); // s는 "elo", b3은 false
		assert(false == b3);
		assert(strcmp(s.GetCString(), "elo") == 0);
		length = s.GetLength();
		assert(3 == length);
	}

	{
		MyString s1("Hello");

		s1.PadLeft(2); // s1: "Hello"
		assert(strcmp(s1.GetCString(), "Hello") == 0);
		unsigned int length = s1.GetLength();
		assert(5 == length);

		s1.PadLeft(8); // s1: "   Hello"
		assert(strcmp(s1.GetCString(), "   Hello") == 0);
		length = s1.GetLength();
		assert(8 == length);

		MyString s2("World");

		s2.PadLeft(3, '-'); // s2: "World"
		assert(strcmp(s2.GetCString(), "World") == 0);
		length = s2.GetLength();
		assert(5 == length);

		s2.PadLeft(7, '-'); // s2: "--World"
		assert(strcmp(s2.GetCString(), "--World") == 0);
		length = s2.GetLength();
		assert(7 == length);
	}

	{
		MyString s1("Hello");

		s1.PadRight(2); // s1: "Hello"
		assert(strcmp(s1.GetCString(), "Hello") == 0);
		unsigned int length = s1.GetLength();
		assert(5 == length);

		s1.PadRight(8); // s1: "Hello   "
		assert(strcmp(s1.GetCString(), "Hello   ") == 0);
		length = s1.GetLength();
		assert(8 == length);

		MyString s2("World");

		s2.PadRight(3, '-'); // s2: "World"
		assert(strcmp(s2.GetCString(), "World") == 0);
		length = s2.GetLength();
		assert(5 == length);

		s2.PadRight(7, '-'); // s2: "World--"
		assert(strcmp(s2.GetCString(), "World--") == 0);
		length = s2.GetLength();
		assert(7 == length);
	}

	{
		MyString s("Hello");

		s.Reverse(); // s: "olleH"
		assert(strcmp(s.GetCString(), "olleH") == 0);
		unsigned int length = s.GetLength();
		assert(5 == length);
	}

	{
		MyString s1("Hello");
		MyString s2("Hello");
		MyString s3("World");

		bool b1 = (s1 == s2); // b1: true
		assert(true == b1);

		bool b2 = (s2 == s3); // b2: false
		assert(false == b2);
	}

	{
		MyString s1("HEllo 123K");
		s1.ToLower(); // s1: "hello 123k"
		assert(strcmp(s1.GetCString(), "hello 123k") == 0);
		unsigned int length = s1.GetLength();
		assert(10 == length);
	}

	{
		MyString s1("HEllo 123K");
		s1.ToUpper(); // s1: "HELLO 123K"
		assert(strcmp(s1.GetCString(), "HELLO 123K") == 0);
		unsigned int length = s1.GetLength();
		assert(10 == length);
	}
}