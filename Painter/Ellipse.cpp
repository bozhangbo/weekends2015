#include "stdafx.h"
#include "Ellipse.h"


CEllipse::CEllipse()
{
}

CEllipse::CEllipse(const Gdiplus::Point& point1, const Gdiplus::Point& point2) :
	_point1(point1),
	_point2(point2)
{

}


CEllipse::~CEllipse()
{
}

void CEllipse::Draw(Gdiplus::Graphics& graphics)
{
	Gdiplus::Pen pen(Gdiplus::Color::Red);
	graphics.DrawEllipse(&pen, _point1.X, _point1.Y, abs(_point1.X - _point2.X), abs(_point1.Y - _point2.Y));

}

void CEllipse::Save(CArchive& ar)
{
	ar << int(ShapeEllipse) << _point1.X << _point1.Y << _point2.X << _point2.Y;
}

void CEllipse::Load(CArchive& ar)
{
	ar >> _point1.X >> _point1.Y >> _point2.X >> _point2.Y;
}