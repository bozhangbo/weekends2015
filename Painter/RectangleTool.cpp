#include "stdafx.h"
#include "RectangleTool.h"
#include "Rectangle.h"
#include <gdiplus.h>

using namespace std;
using namespace Gdiplus;

CRectangleTool::CRectangleTool()
{
}

CRectangleTool::~CRectangleTool()
{
}

void CRectangleTool::OnLButtonDown(UINT nFlags, CPoint point)
{
	_down_point = point;

	_rect = shared_ptr<CRectangle>(new CRectangle(point.x, point.y,
		0,0));
	_rect->SetBorderColor(GetBorderColor());
	_rect->SetFillColor(GetFillColor());
}

void CRectangleTool::OnMouseMove(UINT nFlags, CPoint point)
{
	if ((nFlags & MK_LBUTTON) == MK_LBUTTON && _rect)
	{
		CRect screen_rect(_down_point, point);
		screen_rect.NormalizeRect();

		Rect rect(screen_rect.left, screen_rect.top, screen_rect.Width(), screen_rect.Height());
		_rect->SetRect(rect);
	}
}

std::shared_ptr<CShape> CRectangleTool::GetShape()
{
	return _rect;
}

void CRectangleTool::OnLButtonUp(UINT nFlags, CPoint point)
{
	ASSERT(s_shape_user != nullptr);
	s_shape_user->AddShape(_rect);
}
