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
	SetRect(Gdiplus::Rect(point1.X, point1.Y, abs(point2.X - point1.X), abs(point2.Y - point1.Y)));
}

CLine::~CLine()
{
}

void CLine::Draw(Gdiplus::Graphics& graphics)
{
	Pen pen(GetBorderColor());
	graphics.DrawLine(&pen, _point1, _point2);

	DrawBorder(graphics);
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

int CLine::HitTest(const Gdiplus::Point& point)
{
	return __super::HitTest(point);
}
