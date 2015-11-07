#include "stdafx.h"
#include "Shape.h"


CShape::CShape() :
	_border_color(Gdiplus::Color(0, 255, 0)),
	_fill_color(Gdiplus::Color(192, 255, 192))
{
}


CShape::~CShape()
{
}

void CShape::SetRect(const Gdiplus::Rect& rect)
{
	_rect = rect;
}

const Gdiplus::Rect& CShape::GetRect() const
{
	return _rect;
}

void CShape::Save(CArchive& ar)
{
	ar << _rect.GetLeft() << _rect.GetTop()
		<< _rect.Width << _rect.Height;
}

void CShape::Load(CArchive& ar)
{
	Gdiplus::Point top_left;
	Gdiplus::Size size;
	ar >> top_left.X >> top_left.Y >> size.Width >> size.Height;

	_rect = Gdiplus::Rect(top_left, size);
}

void CShape::SetBorderColor(Gdiplus::Color border_color)
{
	_border_color = border_color;
}

Gdiplus::Color CShape::GetBorderColor() const
{
	return _border_color;
}

void CShape::SetFillColor(Gdiplus::Color fill_color)
{
	_fill_color = fill_color;
}

Gdiplus::Color CShape::GetFillColor() const
{
	return _fill_color;
}

