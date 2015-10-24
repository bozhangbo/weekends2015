#pragma once
#include <gdiplus.h>

class CLine
{
public:
	CLine();
	virtual ~CLine();

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
	void Draw(Gdiplus::Graphics& graphics);
private:
	Gdiplus::Point _point1;
	Gdiplus::Point _point2;
};
