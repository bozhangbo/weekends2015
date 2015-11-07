#pragma once
#include "Shape.h"
#include <gdiplus.h>

class CEllipse :
	public CShape
{
public:
	CEllipse();
	CEllipse(const Gdiplus::Point& point1, const Gdiplus::Point& point2);
	~CEllipse();

	const Gdiplus::Point& GetPoint1() const{
		return _point1;
	}
	void SetPoint1(const Gdiplus::Point& point){
		_point1 = point;
	}

	const Gdiplus::Point& GetPoint2() const{
		return _point2;
	}
	void SetPoint2(const Gdiplus::Point& point){
		_point2 = point;
	}
	virtual void Draw(Gdiplus::Graphics& graphics);
	virtual void Save(CArchive& ar);
	virtual void Load(CArchive& ar);

	private:
		Gdiplus::Point _point1;
		Gdiplus::Point _point2;

};

