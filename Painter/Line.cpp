#include "stdafx.h"
#include "Line.h"

using namespace Gdiplus;

CLine::CLine()
{
}


CLine::~CLine()
{
}

void CLine::Draw(Gdiplus::Graphics& graphics)
{
	Pen pen(Color::Red);
	graphics.DrawLine(&pen, _point1, _point2);
}
