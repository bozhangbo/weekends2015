#pragma once

enum ShapeType
{
	ShapeLine		= 1,
	ShapeRectangle	= 2,
};

class CShape
{
public:
	CShape();
	virtual ~CShape();

	virtual void Draw(Gdiplus::Graphics& graphics) = 0;
	virtual void Save(CArchive& ar) = 0;
	virtual void Load(CArchive& ar) = 0;
};

