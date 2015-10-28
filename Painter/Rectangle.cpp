// Rectangle.cpp : implementation file
//

#include "stdafx.h"
#include "Painter.h"
#include "Rectangle.h"


// CRectangle


CRectangle::CRectangle()
{

}

CRectangle::~CRectangle()
{
} 

void CRectangle::Draw(Gdiplus::Graphics& graphics)
{
	Gdiplus::Pen pen(Gdiplus::Color::Red);
	Gdiplus::Rect rect(_point1.X, _point1.Y, abs(_point2.X - _point1.X), abs(_point2.Y - _point1.Y));
	//graphics.DrawRectangle(&pen,rect);
	graphics.DrawRectangle(&pen, _point1.X, _point1.Y, abs(_point2.X - _point1.X), abs(_point2.Y - _point1.Y));
}



// CRectangle message handlers


