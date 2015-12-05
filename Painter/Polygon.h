#pragma once
#include "Shape.h"

#include <vector>
#include <gdiplus.h>

class CPolygon :
	public CShape
{
public:
	CPolygon();
	virtual ~CPolygon();

	virtual void Draw(Gdiplus::Graphics& graphics);
	virtual void Save(CArchive& ar);
	virtual void Load(CArchive& ar);

	void AddPoint(Gdiplus::Point point);
	void SetPoint(unsigned int index, Gdiplus::Point point);
	unsigned int GetPointCount() const;
private:
	std::vector<Gdiplus::Point> _points;
};

