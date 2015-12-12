#include "stdafx.h"
#include "Shape.h"
#include <Gdiplus.h>

using namespace Gdiplus;

CShape::CShape() :
	_border_color(Gdiplus::Color(0, 255, 0)),
	_fill_color(Gdiplus::Color(192, 255, 192)),
	_selected(false)
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

	ar << _fill_color.GetValue() << _border_color.GetValue();
}

void CShape::Load(CArchive& ar)
{
	Point top_left;
	Size size;
	ar >> top_left.X >> top_left.Y >> size.Width >> size.Height;

	_rect = Gdiplus::Rect(top_left, size);

	ARGB color;
	ar >> color;
	_fill_color = Color(color);

	ar >> color;
	_border_color = Color(color);
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

int CShape::HitTest(const Gdiplus::Point& point)
{
	return _rect.Contains(point);
}

void CShape::Select(bool select)
{
	_selected = select;
}

bool CShape::IsSelected() const
{
	return _selected;
}

void CShape::DrawBorder(Gdiplus::Graphics& graphics)
{
	if (_selected)
	{
		Pen pen(Color::Black);

		graphics.DrawRectangle(&pen, _rect);

		// draw handles
		DrawHandle(graphics, pen, _rect.GetLeft(), _rect.GetTop());
		DrawHandle(graphics, pen, _rect.GetRight(), _rect.GetTop());
		DrawHandle(graphics, pen, _rect.GetRight(), _rect.GetBottom());
		DrawHandle(graphics, pen, _rect.GetLeft(), _rect.GetBottom());

		DrawHandle(graphics, pen, _rect.GetRight(), (_rect.GetTop() + _rect.GetBottom()) / 2);
		DrawHandle(graphics, pen, _rect.GetLeft(), (_rect.GetTop() + _rect.GetBottom()) / 2);
		DrawHandle(graphics, pen, (_rect.GetLeft() + _rect.GetRight()) / 2, _rect.GetTop());
		DrawHandle(graphics, pen, (_rect.GetLeft() + _rect.GetRight()) / 2, _rect.GetBottom());
	}	
}

void CShape::DrawHandle(Graphics& graphics, Pen& pen, INT x, INT y)
{
	Rect rect;
	rect.X = x - 3;
	rect.Y = y - 3;
	rect.Height = rect.Width = 7;

	SolidBrush brush(Color::White);
	graphics.FillRectangle(&brush, rect);
	graphics.DrawRectangle(&pen, rect);
}

