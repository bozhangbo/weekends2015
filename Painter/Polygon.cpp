#include "stdafx.h"
#include "Polygon.h"

using namespace Gdiplus;

CPolygon::CPolygon()
{
}


CPolygon::~CPolygon()
{
}

void CPolygon::Draw(Gdiplus::Graphics& graphics)
{
	Pen pen(GetBorderColor());
	if (_points.size() < 3)
	{
		ASSERT(_points.size() == 2);
		graphics.DrawLine(&pen, _points[0], _points[1]);
	}
	else
	{
		SolidBrush brush(GetFillColor());

		graphics.FillPolygon(&brush, _points.data(), _points.size());
		graphics.DrawPolygon(&pen, _points.data(), _points.size());
	}

}

void CPolygon::Save(CArchive& ar)
{
	ar << (int)ShapePolygon;
	CShape::Save(ar);
	ar << _points.size();
	for (size_t i = 0; i < _points.size(); ++i)
	{
		ar << _points[i].X << _points[i].Y;
	}
}

void CPolygon::Load(CArchive& ar)
{
	CShape::Load(ar);
	size_t point_count = 0;
	ar >> point_count;

	_points.resize(point_count);
	for (size_t i = 0; i < point_count; ++i)
	{
		ar >> _points[i].X >> _points[i].Y;
	}
}

void CPolygon::AddPoint(Gdiplus::Point point)
{
	_points.push_back(point);
}

void CPolygon::SetPoint(unsigned int index, Gdiplus::Point point)
{
	if (index < _points.size())
	{
		_points[index] = point; 
	}
}

unsigned int CPolygon::GetPointCount() const
{
	return _points.size();
}
