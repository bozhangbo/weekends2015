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
	SolidBrush brush(GetFillColor());
	graphics.FillRectangle(&brush, _rect);

	Pen pen(_border_color, 5);
	graphics.DrawRectangle(&pen, _rect);
}

void CRectangle::Save(CArchive& ar)
{
	ar << int(ShapeRectangle);
	__super::Save(ar);
}

