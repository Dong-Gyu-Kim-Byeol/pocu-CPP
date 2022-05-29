#pragma once

#include "Point.h"

namespace lab4
{
	class PolyLine
	{
	public:
		PolyLine();
		PolyLine(const PolyLine& other);
		~PolyLine();

		bool AddPoint(float x, float y);
		bool AddPoint(const Point* point);
		bool RemovePoint(unsigned int i);
		bool TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const;

		const Point* operator[](unsigned int i) const;

	private:
		bool tryGetMinMaxXY(float* outMinX, float* outMinY, float* outMaxX, float* outMaxY) const;

	private:
		static const unsigned int MAX_POINT_COUNT = 10;

	private:
		const Point* mPoints[MAX_POINT_COUNT];
		unsigned int mPointCount;
	};
}