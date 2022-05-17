#include <cassert>
#include <iostream>

#include "TimeSheet.h"

using namespace lab3;

int main()
{
	{
		TimeSheet p("Pope", 3);

		p.AddTime(3); // [ 3 ]
		p.AddTime(11); // [ 3 ]
		p.AddTime(2); // [ 3, 2 ]
		p.AddTime(-1); // [ 3, 2 ]
		p.AddTime(0); // [ 3, 2 ]
		p.AddTime(6); // [ 3, 2, 6 ]
		p.AddTime(4); // [ 3, 2, 6 ]
	}

	{
		TimeSheet c("Pope", 10);
		TimeSheet p(c);

		p.AddTime(2);
		p.AddTime(3);
		p.AddTime(10);

		assert(p.GetTimeEntry(2) == 10);
		assert(p.GetTimeEntry(6) == -1);
		assert(p.GetTimeEntry(0) == 2);
	}

	{
		TimeSheet c("Pope", 10);
		TimeSheet p = c;

		p.AddTime(2);
		p.AddTime(3);
		p.AddTime(10);

		assert(p.GetTotalTime() == 15);
	}

	{
		TimeSheet p("Pope", 10);

		p.AddTime(4);
		p.AddTime(7);
		p.AddTime(6);
		p.AddTime(5);
		p.AddTime(1);
		p.AddTime(2);

		const float averageTime = p.GetAverageTime();
		//assert(averageTime == 4.1667f);
	}

	{
		TimeSheet p("Pope", 10);

		p.AddTime(4);
		p.AddTime(7);
		p.AddTime(6);
		p.AddTime(5);
		p.AddTime(1);
		p.AddTime(2);

		const float standardDeviation = p.GetStandardDeviation();
		//assert(standardDeviation == 2.11476f);
	}

	{
		TimeSheet p("Pope", 7);

		assert(p.GetName() == std::string("Pope"));
	}

	{
		TimeSheet employee1("John", 10);
		employee1.AddTime(4);
		employee1.AddTime(7);
		std::cout << "Employee: " << employee1.GetName() << " / AverageTime: " << employee1.GetAverageTime() << " / TotalTime: " << employee1.GetTotalTime() << std::endl;
	}

	return 0;
}