#include "stdafx.h"
#include "Line.h"

using namespace Gdiplus;

CLine::CLine()
{
}

CLine::CLine(const Gdiplus::Point& point1, const Gdiplus::Point& point2)
{
	_point1 = point1;
	_point2 = point2;
}

CLine::~CLine()
{
}

void CLine::Draw(Gdiplus::Graphics& graphics)
{
	Pen pen(GetBorderColor());
	graphics.DrawLine(&pen, _point1, _point2);
}

void CLine::Save(CArchive& ar)
{
	ar << int(ShapeLine);
	CShape::Save(ar);
	ar << _point1.X << _point1.Y << _point2.X << _point2.Y;
}

void CLine::Load(CArchive& ar)
{
	CShape::Load(ar);
 	ar >> _point1.X >> _point1.Y >> _point2.X >> _point2.Y;
}
