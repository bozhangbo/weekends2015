#pragma once

#include <Gdiplus.h>

enum ShapeType
{
	ShapeLine = 1,
	ShapeRectangle = 2,
	ShapeEllipse = 3,
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

protected:
	Gdiplus::Rect _rect;
};

