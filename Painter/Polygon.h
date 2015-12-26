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
	virtual void OnSetRect();

	void AddPoint(Gdiplus::Point point);
	void SetPoint(unsigned int index, Gdiplus::Point point);
	unsigned int GetPointCount() const;
	void SetRect();
	void Finalize();

	virtual void OnEndMove() override;

private:
	std::vector<Gdiplus::Point> _points;
	std::vector<Gdiplus::PointF> _relative_points;
};

