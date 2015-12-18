#include "stdafx.h"

#include "LineTool.h"
#include "line.h"
#include <gdiplus.h>

using namespace std;
using namespace Gdiplus;

CLineTool::CLineTool()
{
}


CLineTool::~CLineTool()
{
}

void CLineTool::OnLButtonDown(UINT nFlags, CPoint point)
{
	_line = shared_ptr<CLine>(new CLine(Point(point.x, point.y),
		 			Point(point.x, point.y)));
	_line->SetBorderColor(GetBorderColor());
}

void CLineTool::OnMouseMove(UINT nFlags, CPoint point)
{
	if ((nFlags & MK_LBUTTON) == MK_LBUTTON && _line)
	{
		_line->SetPoint2(Point(point.x, point.y));

		Gdiplus::Point point1 = _line->GetPoint1();
		_line->SetRect(Gdiplus::Rect(point1.X, point1.Y, abs(point.x - point1.X), abs(point.y - point1.Y)));
	}
}

std::shared_ptr<CShape> CLineTool::GetShape()
{
	return _line;
}

void CLineTool::OnLButtonUp(UINT nFlags, CPoint point)
{
	s_shape_user->AddShape(_line);
}
