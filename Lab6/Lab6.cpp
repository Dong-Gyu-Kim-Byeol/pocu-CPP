#include <cmath>
#include <unordered_map>
#include <map>
#include <ranges>

#include "Lab6.h"

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		int sum = 0;

		for (const int num : v)
		{
			sum += num;
		}

		return sum;
	}

	int Min(const std::vector<int>& v)
	{
		int min = INT32_MAX;

		for (const int num : v)
		{
			min = std::min(min, num);
		}

		return min;
	}

	int Max(const std::vector<int>& v)
	{
		int max = INT32_MIN;

		for (const int num : v)
		{
			max = std::max(max, num);
		}

		return max;
	}

	float Average(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0.f;
		}

		const float sum = static_cast<float>(Sum(v));
		const float count = static_cast<float>(v.size());
		return sum / count;
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0;
		}

		std::unordered_map<int, size_t> countMap(v.size() * 2);

		int maxNum = v[0];
		size_t maxCount = 1;
		for (const int num : v)
		{
			const size_t count = ++countMap[num];
			if (maxCount < count)
			{
				maxNum = num;
				maxCount = count;
			}
		}

		return maxNum;
	}

	void SortDescending(std::vector<int>& v)
	{
		std::map<int, size_t> countMap;

		for (const int num : v)
		{
			++countMap[num];
		}

		int vIndex = 0;
		for (const auto& [num, count] : countMap | std::views::reverse)
		{
			for (int i = 0; i < count; ++i)
			{
				v[vIndex++] = num;
			}
		}
	}

}