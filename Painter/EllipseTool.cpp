#include "stdafx.h"
#include "EllipseTool.h"
#include "Ellipse.h"
#include <gdiplus.h>

using namespace std;
using namespace Gdiplus;


CEllipseTool::CEllipseTool()
{
}


CEllipseTool::~CEllipseTool()
{
}

void CEllipseTool::OnLButtonDown(UINT nFlags, CPoint point)
{
	_ellipse = shared_ptr<CEllipse>(new CEllipse(Point(point.x, point.y),
		Point(point.x, point.y)));

	_ellipse->SetBorderColor(GetBorderColor());
	_ellipse->SetFillColor(GetFillColor());
}

void CEllipseTool::OnMouseMove(UINT nFlags, CPoint point)
{
	if ((nFlags & MK_LBUTTON) == MK_LBUTTON && _ellipse)
	{
		Gdiplus::Rect rect(_ellipse->GetRect().GetLeft(),_ellipse->GetRect().GetTop(),
			point.x-_ellipse->GetRect().GetLeft(),point.y-_ellipse->GetRect().GetTop());
		_ellipse->SetRect(rect);
	}
}

std::shared_ptr<CShape> CEllipseTool::GetShape()
{
	return _ellipse;
}

void CEllipseTool::OnLButtonUp(UINT nFlags, CPoint point)
{
	s_shape_user->AddShape(_ellipse);
}
