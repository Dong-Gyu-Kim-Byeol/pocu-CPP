#include <cstring>
#include <cmath>
#include <cassert>

#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine() :
		mPointCount(0),
		mPoints{ 0, }
	{
	}

	PolyLine::PolyLine(const PolyLine& other) :
		mPointCount(other.mPointCount),
		mPoints{ 0, }
	{

		for (int i = 0; i < other.mPointCount; ++i)
		{
			const Point* newPoint = new Point(*other.mPoints[i]);
			mPoints[i] = newPoint;
		}
	}

	PolyLine::~PolyLine()
	{
		for (int i = 0; i < mPointCount; ++i)
		{
			delete mPoints[i];
			mPoints[i] = nullptr;
		}

		mPointCount = 0;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		assert(0 <= mPointCount);
		if (mPointCount >= MAX_POINT_COUNT)
		{
			return false;
		}

		const Point* newPoint = new Point(x, y);

		const bool bIsAdd = AddPoint(newPoint);
		if (!bIsAdd)
		{
			delete newPoint;
			return false;
		}

		return true;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		assert(0 <= mPointCount);
		if (mPointCount >= MAX_POINT_COUNT)
		{
			return false;
		}

		mPoints[mPointCount] = point;
		++mPointCount;

		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		const int lastIndex = getLastIndex();
		if (lastIndex < i)
		{
			return false;
		}

		for (unsigned int index = i; index <= lastIndex - 1; ++index)
		{
			mPoints[index] = mPoints[index + 1];
		}
		mPoints[lastIndex] = nullptr;

		--mPointCount;
		return true;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		float minX = 0.f;
		float minY = 0.f;
		float maxX = 0.f;
		float maxY = 0.f;
		const bool bTryGetMinMaxXY = tryGetMinMaxXY(&minX, &minY, &maxX, &maxY);
		if (!bTryGetMinMaxXY)
		{
			return false;
		}

		if (minX >= maxX || minY >= maxY)
		{
			return false;
		}

		*outMin = Point(minX, minY);
		*outMax = Point(maxX, maxY);

		return true;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		const int lastIndex = getLastIndex();
		if (lastIndex < i)
		{
			return nullptr;
		}

		return mPoints[i];
	}


	// private
	int PolyLine::getLastIndex() const
	{
		assert(0 <= mPointCount);
		return mPointCount - 1;
	}

	bool PolyLine::tryGetMinMaxXY(float* outMinX, float* outMinY, float* outMaxX, float* outMaxY) const
	{
		assert(0 <= mPointCount);
		if (mPointCount <= 0)
		{
			return false;
		}

		const int lastIndex = getLastIndex();
		*outMinX = mPoints[0]->GetX();
		*outMinY = mPoints[0]->GetY();
		*outMaxX = mPoints[0]->GetX();
		*outMaxY = mPoints[0]->GetY();

		for (int i = 0; i <= lastIndex; ++i)
		{
			const Point& point = *mPoints[i];

			// min
			if (*outMinX > point.GetX())
			{
				*outMinX = point.GetX();
			}

			if (*outMinY > point.GetY())
			{
				*outMinY = point.GetY();
			}

			// max
			if (*outMaxX < point.GetX())
			{
				*outMaxX = point.GetX();
			}

			if (*outMaxY < point.GetY())
			{
				*outMaxY = point.GetY();
			}
		}

		return true;
	}

}