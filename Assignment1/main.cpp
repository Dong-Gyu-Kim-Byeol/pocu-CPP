#include "MyString.h"

#include <cassert>
#include <string>
#include <iostream>

void Test();
void WikiTest2();
void WikiTest3();
void WikiTest4();

using namespace std;
using namespace assignment1;

int main()
{
	// 여기에 중단점을 설정해서 b 값을 살펴보거나
	// 아래와 같이 assert() 함수를 써보세요
	// assert(s == s2);	// #include <cassert>이 필요

	Test();
	WikiTest2();
	WikiTest3();
	WikiTest4();

	return 0;
}

void Test()
{
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

void WikiTest2()
{
	MyString str(nullptr);
	str.Append("Hello");
	assert(strcmp(str.GetCString(), "Hello") == 0);
	std::cout << "nullptr 생성 이후 Append : " << str.GetCString() << std::endl;


	MyString constructorTest("Hello");
	std::cout << "문자열 생성 : " << constructorTest.GetCString() << std::endl;
	std::cout << "문자열 생성 길이 : " << constructorTest.GetLength() << std::endl;
	assert(strcmp(constructorTest.GetCString(), "Hello") == 0);
	assert(constructorTest.GetLength() == 5);


	std::cout << std::hex;
	MyString originalStr("Hello");
	MyString copyStr(originalStr);
	int originalStrAddress = reinterpret_cast<int>(originalStr.GetCString());
	int copyStrAddress = reinterpret_cast<int>(copyStr.GetCString());
	std::cout << "원본 : " << originalStr.GetCString() << ", 원본 주소 : " << originalStrAddress << std::endl;
	std::cout << "복사본 : " << copyStr.GetCString() << ", 복사본 주소 : " << copyStrAddress << std::endl;
	assert(originalStrAddress != copyStrAddress);
	assert(strcmp(originalStr.GetCString(), "Hello") == 0);
	assert(strcmp(copyStr.GetCString(), "Hello") == 0);


	MyString appendTestFunctional("Hello");
	appendTestFunctional.Append(" World");
	std::cout << "문자열 이어 붙히기 함수형 내부값 변경 : " << appendTestFunctional.GetCString() << std::endl;
	assert(strcmp(appendTestFunctional.GetCString(), "Hello World") == 0);


	MyString appendTestOperator1("Hello");
	MyString appendTestOperator2(" World");
	MyString appendTestOperator3 = appendTestOperator1 + appendTestOperator2;
	std::cout << "문자열 이어 붙히기 연산자 반환 : " << appendTestOperator3.GetCString() << std::endl;
	assert(strcmp(appendTestOperator3.GetCString(), "Hello World") == 0);


	MyString indexOfTest("Hello");
	assert(indexOfTest.IndexOf("el") == 1);
	assert(indexOfTest.IndexOf("ll") == 2);
	assert(indexOfTest.IndexOf("l") == 2);
	assert(indexOfTest.IndexOf("asd") == -1);
	assert(indexOfTest.IndexOf("") == 0);
	assert(indexOfTest.IndexOf(nullptr) == -1);
	assert(indexOfTest.IndexOf("lo") == 3);

	assert(indexOfTest.LastIndexOf("l") == 3);
	assert(indexOfTest.LastIndexOf("asd") == -1);
	assert(indexOfTest.LastIndexOf(nullptr) == -1);
	assert(indexOfTest.LastIndexOf("He") == 0);

	MyString emptyIndexOfTest("");
	assert(emptyIndexOfTest.IndexOf("a") == -1);
	assert(emptyIndexOfTest.IndexOf("") == 0);
	assert(emptyIndexOfTest.LastIndexOf("") == emptyIndexOfTest.GetLength());

	std::cout << std::boolalpha;
	MyString removeTest("Hello");
	bool b1 = removeTest.RemoveAt(0); // s는 "ello", b1은 true
	std::cout << "Hello의 첫글자 지우기 : " << removeTest.GetCString() << ", 성공여부 : " << b1 << std::endl;
	assert(strcmp(removeTest.GetCString(), "ello") == 0);
	assert(b1 == true);

	bool b2 = removeTest.RemoveAt(3); // s는 "ell", b2은 true
	std::cout << "ello의 네번째 글자 지우기 : " << removeTest.GetCString() << ", 성공여부 : " << b2 << std::endl;
	assert(strcmp(removeTest.GetCString(), "ell") == 0);
	assert(b2 == true);

	bool b3 = removeTest.RemoveAt(4); // s는 "ell", b3은 false
	std::cout << "ell의 다섯번째 글자 지우기 : " << removeTest.GetCString() << ", 성공여부 : " << b3 << std::endl;
	assert(strcmp(removeTest.GetCString(), "ell") == 0);
	assert(b3 == false);



	MyString padLeftTest1("Hello");
	int previousPadLeftTest1StrAddress = reinterpret_cast<int>(padLeftTest1.GetCString());
	padLeftTest1.PadLeft(2); // s1: "Hello"
	int currentPadLeftTest1StrAddress = reinterpret_cast<int>(padLeftTest1.GetCString());
	std::cout << padLeftTest1.GetCString() << std::endl;
	assert(previousPadLeftTest1StrAddress == currentPadLeftTest1StrAddress);
	assert(strcmp(padLeftTest1.GetCString(), "Hello") == 0);

	padLeftTest1.PadLeft(8); // s1: "   Hello"
	assert(strcmp(padLeftTest1.GetCString(), "   Hello") == 0);
	std::cout << padLeftTest1.GetCString() << std::endl;



	MyString padLeftTest2("Hello");
	int previousPadLeftTest2StrAddress = reinterpret_cast<int>(padLeftTest2.GetCString());
	padLeftTest2.PadLeft(3, '-'); // s1: "Hello"
	int currentPadLeftTest2StrAddress = reinterpret_cast<int>(padLeftTest2.GetCString());
	std::cout << padLeftTest2.GetCString() << std::endl;
	assert(previousPadLeftTest2StrAddress == currentPadLeftTest2StrAddress);
	assert(strcmp(padLeftTest2.GetCString(), "Hello") == 0);

	padLeftTest2.PadLeft(7, '-'); // s1: "   Hello"
	std::cout << padLeftTest2.GetCString() << std::endl;
	assert(strcmp(padLeftTest2.GetCString(), "--Hello") == 0);



	MyString padRightTest1("Hello");
	int previousPadRightTest1StrAddress = reinterpret_cast<int>(padRightTest1.GetCString());
	padRightTest1.PadRight(2); // s1: "Hello"
	int currentPadRightTest1StrAddress = reinterpret_cast<int>(padRightTest1.GetCString());
	std::cout << padRightTest1.GetCString() << std::endl;
	assert(previousPadRightTest1StrAddress == currentPadRightTest1StrAddress);
	assert(strcmp(padRightTest1.GetCString(), "Hello") == 0);

	padRightTest1.PadRight(8); // s1: "   Hello"
	std::cout << padRightTest1.GetCString() << "I" << std::endl;
	assert(strcmp(padRightTest1.GetCString(), "Hello   ") == 0);



	MyString padRightTest2("Hello");
	int previousPadRightTest2StrAddress = reinterpret_cast<int>(padRightTest2.GetCString());
	padRightTest2.PadRight(3, '-'); // s1: "Hello"
	int currentPadRightTest2StrAddress = reinterpret_cast<int>(padRightTest2.GetCString());
	std::cout << padRightTest2.GetCString() << std::endl;
	assert(previousPadRightTest2StrAddress == currentPadRightTest2StrAddress);
	assert(strcmp(padRightTest2.GetCString(), "Hello") == 0);

	padRightTest2.PadRight(7, '-'); // s1: "   Hello"
	std::cout << padRightTest2.GetCString() << std::endl;
	assert(strcmp(padRightTest2.GetCString(), "Hello--") == 0);



	MyString reverseTest("Hello");
	int previousReverseTestStrAddress = reinterpret_cast<int>(reverseTest.GetCString());
	reverseTest.Reverse();
	int currentReverseTestStrAddress = reinterpret_cast<int>(reverseTest.GetCString());
	std::cout << "문자를 거꾸로 : " << reverseTest.GetCString() << std::endl;
	assert(strcmp(reverseTest.GetCString(), "olleH") == 0);



	MyString equelsOperatorTest1("Hello");
	MyString equelsOperatorTest2("Hello");
	MyString equelsOperatorTest3("World");
	assert((equelsOperatorTest1 == equelsOperatorTest2) == true);
	assert((equelsOperatorTest1 == equelsOperatorTest3) == false);



	MyString toLowerTest("HEllo 123K");
	toLowerTest.ToLower(); // s1: "hello 123k"
	assert(strcmp(toLowerTest.GetCString(), "hello 123k") == 0);
	std::cout << "전체 문자 소문자로 변경 : " << toLowerTest.GetCString() << std::endl;



	MyString toUpperTest("HEllo 123K");
	toUpperTest.ToUpper(); // s1: "HELLO 123K"
	assert(strcmp(toUpperTest.GetCString(), "HELLO 123K") == 0);
	std::cout << "전체 문자 대문자로 변경 : " << toUpperTest.GetCString() << std::endl;
}

void WikiTest3()
{
	//	메모리 체크용 변수
	int beforeAddress1;
	int beforeAddress2;

	MyString testString1("Happy Happy Days");
	MyString testString2("Happy Days");
	MyString testString3("Happy Days");
	MyString testString4("");

	//	Operator == 관련
	beforeAddress1 = (int)testString2.GetCString();
	beforeAddress2 = (int)testString3.GetCString();
	if (testString2 == testString3);
	assert(beforeAddress1 == (int)testString2.GetCString());
	assert(beforeAddress2 == (int)testString3.GetCString());
	cout << "D2_NoMallocInCompareSameLength 통과" << endl;

	beforeAddress1 = (int)testString1.GetCString();
	beforeAddress2 = (int)testString2.GetCString();
	if (testString1 == testString2);
	assert(beforeAddress1 == (int)testString1.GetCString());
	assert(beforeAddress2 == (int)testString2.GetCString());
	cout << "D5_NoMallocInCompareDifferentLength 통과" << endl;

	//	IndexOf, LastOfIndex 관련
	beforeAddress1 = (int)testString1.GetCString();
	testString1.IndexOf("Happy");
	testString1.IndexOf("");
	assert(beforeAddress1 == (int)testString1.GetCString());

	beforeAddress1 = (int)testString1.GetCString();
	testString1.LastIndexOf("Happy");
	testString1.LastIndexOf("");
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "E5_NoMallocInIndexOf 통과" << endl;

	//	ToUpper, ToLower 관련
	beforeAddress1 = (int)testString1.GetCString();
	testString1.ToUpper();
	testString1.ToLower();
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "F3_NoMallocInUpperLower 통과" << endl;

	//	Reverse 관련
	beforeAddress1 = (int)testString1.GetCString();
	testString1.Reverse();
	testString1.Reverse();
	assert(beforeAddress1 == (int)testString1.GetCString());
	beforeAddress1 = (int)testString4.GetCString();
	testString4.Reverse();
	assert(beforeAddress1 == (int)testString4.GetCString());
	cout << "G4_NoMallocInReverse 통과" << endl;

	//	Append 관련
	beforeAddress1 = (int)testString1.GetCString();
	testString1.Append("");
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "H3_NoMallocInAppendEmpty 통과" << endl;

	//	 RemoveAt 관련
	beforeAddress1 = (int)testString4.GetCString();
	testString4.RemoveAt(0);
	assert(beforeAddress1 == (int)testString4.GetCString());
	cout << "J2_RemoveAtNoMallocOnEmpty 통과" << endl;

	//	PadLeft, PadRight 관련
	beforeAddress1 = (int)testString1.GetCString();
	testString1.PadLeft(16);
	testString1.PadLeft(16, '*');
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "K4_NoMallocInPadLeftShorter 통과" << endl;

	beforeAddress1 = (int)testString1.GetCString();
	testString1.PadRight(16);
	testString1.PadRight(16, '*');
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "L4_NoMallocInPadRightShorter 통과" << endl;

	//	InterLeave 관련

	beforeAddress1 = (int)testString1.GetCString();
	testString1.PadRight(16);
	testString1.PadRight(16, '*');
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "L4_NoMallocInPadRightShorter 통과" << endl;

	//	InterLeave 관련
	beforeAddress1 = (int)testString1.GetCString();
	testString1.Interleave("");
	assert(beforeAddress1 == (int)testString1.GetCString());
	cout << "M3_NoMallocInInterleaveEmpty 통과" << endl;
}

void WikiTest4()
{
	{
		std::string srcHi = "Hello, world!";
		std::string srcBye = "Bye, world!";
		std::string srcHiBye = srcHi + srcBye;
		std::string srcEmpty = "";

		MyString hi(srcHi.c_str());
		MyString hi2(hi);
		MyString empty(srcEmpty.c_str());

		assert(hi.GetLength() == srcHi.size());
		assert(hi2.GetLength() == srcHi.size());
		assert(empty.GetLength() == 0);

		assert(hi.GetCString() != srcHi.c_str());
		assert(hi2.GetCString() != srcHi.c_str());
		assert(hi.GetCString() != hi2.GetCString());
		assert(empty.GetCString() != srcEmpty.c_str());

		assert(strcmp(hi.GetCString(), srcHi.c_str()) == 0);
		assert(strcmp(hi2.GetCString(), srcHi.c_str()) == 0);
		assert(strcmp(empty.GetCString(), srcEmpty.c_str()) == 0);

		hi.Append(srcBye.c_str());
		assert(hi.GetLength() == srcHiBye.size());
		assert(strcmp(hi.GetCString(), srcHiBye.c_str()) == 0);

		hi2.Append(NULL);
		assert(hi2.GetLength() == srcHi.size());
		assert(strcmp(hi2.GetCString(), srcHi.c_str()) == 0);

		hi2.Append("");
		assert(hi2.GetLength() == srcHi.size());
		assert(strcmp(hi2.GetCString(), srcHi.c_str()) == 0);
	}

	{
		std::string srcHi = "Hello, world!";
		std::string srcBye = "Bye, world!";
		std::string srcHiBye = srcHi + srcBye;

		MyString hi(srcHi.c_str());
		MyString bye(srcBye.c_str());
		MyString hiBye = hi + bye;
		MyString empty("");
		MyString hi2 = hi + empty;

		assert(strcmp(hi.GetCString(), srcHi.c_str()) == 0);
		assert(strcmp(bye.GetCString(), srcBye.c_str()) == 0);
		assert(strcmp(hiBye.GetCString(), srcHiBye.c_str()) == 0);
		assert(strcmp(hi2.GetCString(), srcHi.c_str()) == 0);
		assert(hi.GetLength() == srcHi.size());
		assert(bye.GetLength() == srcBye.size());
		assert(hiBye.GetLength() == srcHiBye.size());
		assert(hi2.GetLength() == srcHi.size());

		assert(hi.IndexOf(NULL) == -1);
		assert(hi.IndexOf("") == srcHi.find(""));
		assert(hi.IndexOf("l") == srcHi.find("l"));
		assert(hi.IndexOf("lo") == srcHi.find("lo"));
		assert(hi.IndexOf("ld") == srcHi.find("ld"));
		assert(hi.IndexOf("1234") == srcHi.find("1234"));
		assert(hi.IndexOf(", world!") == srcHi.find(", world!"));
		assert(hi.IndexOf("Hello, world!") == srcHi.find("Hello, world!"));

		assert(empty.IndexOf(NULL) == -1);
		assert(empty.IndexOf("") == 0);
		assert(empty.IndexOf("l") == -1);
		assert(empty.IndexOf("lo") == -1);
		assert(empty.IndexOf("ld") == -1);
		assert(empty.IndexOf("1234") == -1);
		assert(empty.IndexOf(", world!") == -1);
		assert(empty.IndexOf("Hello, world!") == -1);

		assert(hi.LastIndexOf(NULL) == -1);
		int li1 = hi.LastIndexOf("");
		int li2 = srcHi.rfind("");
		assert(li1 == li2);
		assert(hi.LastIndexOf("l") == srcHi.rfind("l"));
		assert(hi.LastIndexOf("lo") == srcHi.rfind("lo"));
		assert(hi.LastIndexOf("ld") == srcHi.rfind("ld"));
		assert(hi.LastIndexOf("1234") == srcHi.rfind("1234"));
		assert(hi.LastIndexOf(", world!") == srcHi.rfind(", world!"));
		assert(hi.LastIndexOf("Hello, world!") == srcHi.rfind("Hello, world!"));
	}

	{
		std::string srcAaa = "aaaaa";
		std::string srcBbb = "bbbbb";
		MyString aaa(srcAaa.c_str());
		MyString bbb(srcBbb.c_str());
		MyString empty("");

		empty.Interleave(NULL);
		assert(empty.GetLength() == 0);
		assert(strcmp(empty.GetCString(), "") == 0);

		empty.Interleave("");
		assert(empty.GetLength() == 0);
		assert(strcmp(empty.GetCString(), "") == 0);

		aaa.Interleave(NULL);
		assert(aaa.GetLength() == 5);
		assert(strcmp(aaa.GetCString(), "aaaaa") == 0);

		aaa.Interleave("");
		assert(aaa.GetLength() == 5);
		assert(strcmp(aaa.GetCString(), "aaaaa") == 0);

		aaa.Interleave(srcBbb.c_str());
		assert(aaa.GetLength() == 10);
		assert(strcmp(aaa.GetCString(), "ababababab") == 0);

		assert(!aaa.RemoveAt(UINT32_MAX));
		assert(aaa.GetLength() == 10);
		assert(strcmp(aaa.GetCString(), "ababababab") == 0);

		assert(aaa.RemoveAt(1));
		assert(aaa.GetLength() == 9);
		assert(strcmp(aaa.GetCString(), "aabababab") == 0);

		assert(aaa.RemoveAt(2));
		assert(aaa.GetLength() == 8);
		assert(strcmp(aaa.GetCString(), "aaababab") == 0);

		assert(aaa.RemoveAt(3));
		assert(aaa.GetLength() == 7);
		assert(strcmp(aaa.GetCString(), "aaaabab") == 0);

		assert(aaa.RemoveAt(4));
		assert(aaa.GetLength() == 6);
		assert(strcmp(aaa.GetCString(), "aaaaab") == 0);

		assert(aaa.RemoveAt(5));
		assert(aaa.GetLength() == 5);
		assert(strcmp(aaa.GetCString(), "aaaaa") == 0);

		aaa.PadLeft(0, '-');
		assert(aaa.GetLength() == 5);
		assert(strcmp(aaa.GetCString(), "aaaaa") == 0);

		aaa.PadLeft(5, '-');
		assert(aaa.GetLength() == 5);
		assert(strcmp(aaa.GetCString(), "aaaaa") == 0);

		aaa.PadLeft(10, '-');
		assert(aaa.GetLength() == 10);
		assert(strcmp(aaa.GetCString(), "-----aaaaa") == 0);

		bbb.PadRight(0, '-');
		assert(bbb.GetLength() == 5);
		assert(strcmp(bbb.GetCString(), "bbbbb") == 0);

		bbb.PadRight(5, '-');
		assert(bbb.GetLength() == 5);
		assert(strcmp(bbb.GetCString(), "bbbbb") == 0);

		bbb.PadRight(10, '-');
		assert(bbb.GetLength() == 10);
		assert(strcmp(bbb.GetCString(), "bbbbb-----") == 0);

		MyString nums("0123456789");
		nums.Reverse();
		assert(nums.GetLength() == 10);
		assert(strcmp(nums.GetCString(), "9876543210") == 0);
	}

	{
		assert(MyString("") == MyString(""));
		assert(MyString("a") == MyString("a"));
		assert(!(MyString("a") == MyString("b")));
		assert(!(MyString(" ") == MyString("  ")));
		assert(MyString("ajweoifuj23q8o9ur2139y4i2u") == MyString("ajweoifuj23q8o9ur2139y4i2u"));
		assert(!(MyString("ajweoifuj23q8o9ur2139y4i2o") == MyString("ajweoifuj23q8o9ur2139y4i2u")));

		MyString mong("mong");
		MyString shell("shell");
		const char* mongOldStr = mong.GetCString();
		const char* shellOldStr = shell.GetCString();

		assert(!(mong == shell));
		assert(mong.GetLength() != shell.GetLength());
		assert(mong.GetCString() == mongOldStr);
		assert(mong.GetCString() != shell.GetCString());

		mong = shell;

		assert(mong == shell);
		assert(mong.GetLength() == shell.GetLength());
		assert(mong.GetCString() != mongOldStr);

		assert(mong.GetCString() != shell.GetCString());

		assert(shell.GetCString() == shellOldStr);

		shell = shell;

		assert(shell.GetCString() == shellOldStr);

		MyString lowerCase("a bc;;def*g*hi_jk@");
		MyString upperCase("A BC;;DEF*G*HI_JK@");
		MyString mixedCase("a BC;;def*G*hI_Jk@");

		MyString case1 = lowerCase;
		MyString case2 = upperCase;
		MyString case3 = mixedCase;

		case1.ToLower();
		case2.ToLower();
		case3.ToLower();

		assert(case1 == lowerCase);
		assert(case2 == lowerCase);
		assert(case3 == lowerCase);

		case1 = lowerCase;
		case2 = upperCase;
		case3 = mixedCase;

		case1.ToUpper();
		case2.ToUpper();
		case3.ToUpper();

		assert(case1 == upperCase);
		assert(case2 == upperCase);
		assert(case3 == upperCase);
	}
}