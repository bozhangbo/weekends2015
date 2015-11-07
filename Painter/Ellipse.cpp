#include "stdafx.h"
#include "Ellipse.h"


CEllipse::CEllipse()
{
}

CEllipse::CEllipse(const Gdiplus::Point& point1, const Gdiplus::Point& point2) 
{
	SetRect(Gdiplus::Rect(point1.X, point1.Y, abs(point2.X - point1.X), abs(point2.Y - point1.Y)));
}

CEllipse::~CEllipse()
{
}

void CEllipse::Draw(Gdiplus::Graphics& graphics)
{
	Gdiplus::Pen pen(Gdiplus::Color::Red);
	graphics.DrawEllipse(&pen, _rect);
}

void CEllipse::Save(CArchive& ar)
{
	ar << int(ShapeEllipse);

	CShape::Save(ar);
}

