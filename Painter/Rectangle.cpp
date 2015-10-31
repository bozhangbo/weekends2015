#include "stdafx.h"
#include "Rectangle.h"

using namespace Gdiplus;

CRectangle::CRectangle()
{
}

CRectangle::CRectangle(INT x, INT y, INT width, INT height)
{
	_top_left.X = x;
	_top_left.Y = y;
	_size.Width = width;
	_size.Height = height;
}


CRectangle::~CRectangle()
{
}

void CRectangle::Draw(Gdiplus::Graphics& graphics)
{
	// SolidBrush brush(Color::Black);
	Pen pen(Color::Black);

	graphics.DrawRectangle(&pen, _top_left.X, _top_left.Y, _size.Width, _size.Height);
}

void CRectangle::Save(CArchive& ar)
{
	ar << int(ShapeRectangle) << _top_left.X << _top_left.Y << _size.Width << _size.Height;
}

void CRectangle::Load(CArchive& ar)
{
	ar >> _top_left.X >> _top_left.Y >> _size.Width >> _size.Height;
}
