#pragma once
#include <gdiplus.h>

// CRectangle

class CRectangle 
{	
public:
	CRectangle();
	virtual ~CRectangle();

	const Gdiplus::Point& GetPoint1() const{
		return _point1;
	}
	const Gdiplus::Point& GetPoint2() const{
		return _point2;
	}
	void SetPoint1(const Gdiplus::Point& point)
	{
		_point1 = point;
	}
	void SetPoint2(const Gdiplus::Point& point)
	{
		_point2 = point;
	}
	void Draw(Gdiplus::Graphics& graphics);
private:
	Gdiplus::Point _point1;
	Gdiplus::Point _point2;

};


