#pragma once

#include <Gdiplus.h>

enum ShapeType
{
	ShapeLine = 1,
	ShapeRectangle = 2,
	ShapeEllipse = 3,
	ShapePolygon = 4,
};

class CShape
{
public:
	CShape();
	virtual ~CShape();

	virtual void Draw(Gdiplus::Graphics& graphics) = 0;
	virtual void Save(CArchive& ar);
	virtual void Load(CArchive& ar);
	void SetRect(const Gdiplus::Rect& rect);
	const Gdiplus::Rect& GetRect() const;
	void SetBorderColor(Gdiplus::Color border_color);
	Gdiplus::Color GetBorderColor() const;
	void SetFillColor(Gdiplus::Color fill_color);
	Gdiplus::Color GetFillColor() const;

protected:
	Gdiplus::Rect _rect;
	Gdiplus::Color _border_color;
	Gdiplus::Color _fill_color;
};

