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
		graphics.DrawPolygon(&pen, _points.data(), _points.size());

		SolidBrush brush(GetFillColor());
		graphics.FillPolygon(&brush, _points.data(), _points.size());
	}

}

void CPolygon::Save(CArchive& ar)
{

}

void CPolygon::Load(CArchive& ar)
{

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
