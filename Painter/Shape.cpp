#include "stdafx.h"
#include "Shape.h"


CShape::CShape()
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
