#include "Lab2.h"

#include <iomanip>

using namespace std;

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		const size_t OCT_COLLUM_LENTH = 12;
		const size_t DEC_COLLUM_LENTH = 11;
		const size_t HEX_COLLUM_LENTH = 9;

		bool bIsFirst = true;

		while (true)
		{
			int num = 0;
			in >> num;

			if (in.fail())
			{
				in.clear();
				in.ignore();
				in.clear();
				continue;
			}

			if (bIsFirst)
			{
				bIsFirst = false;

				out << setw(OCT_COLLUM_LENTH) << "oct";
				out << setw(DEC_COLLUM_LENTH) << "dec";
				out << setw(HEX_COLLUM_LENTH) << "hex" << endl;
				out << setw(OCT_COLLUM_LENTH) << "------------";
				out << setw(DEC_COLLUM_LENTH) << "----------";
				out << setw(HEX_COLLUM_LENTH) << "--------" << endl;
			}

			out << setw(OCT_COLLUM_LENTH) << right << oct << num;
			out << setw(DEC_COLLUM_LENTH) << right << dec << num;
			out << setw(HEX_COLLUM_LENTH) << right << uppercase << hex << num << endl;

			if (in.eof())
			{
				in.clear();
				break;
			}
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		const size_t COLLUM_LENTH_1 = 5;
		const size_t COLLUM_LENTH_2 = 15;

		bool bIsFirst = true;
		float max = 0.f;

		while (true)
		{
			float num = 0.f;
			in >> num;

			if (in.fail())
			{
				in.clear();
				in.ignore();
				in.clear();
				continue;
			}

			if (bIsFirst)
			{
				bIsFirst = false;
				max = num;
			}
			max = std::max(max, num);

			out << setw(COLLUM_LENTH_1) << " " << setw(COLLUM_LENTH_2) << internal << showpos << fixed << showpoint << setprecision(3) << num << endl;

			if (in.eof())
			{
				in.clear();
				break;
			}
		}

		out << setw(COLLUM_LENTH_1) << left << "max:" << setw(COLLUM_LENTH_2) << internal << showpos << fixed << showpoint << setprecision(3) << max << endl;
	}
}