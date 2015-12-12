#include "stdafx.h"
#include "SelectTool.h"
#include <gdiplus.h>
#include "Shape.h"

using namespace std;
using namespace Gdiplus;

CSelectTool::CSelectTool()
{
}


CSelectTool::~CSelectTool()
{
}

void CSelectTool::OnLButtonDown(UINT nFlags, CPoint point)
{
	const auto & shapes = s_shape_user->Shapes();
	for (auto iter = shapes.begin(); iter != shapes.end(); ++iter)
	{
		(*iter)->Select(false);
	}

	for (auto iter = shapes.rbegin(); iter != shapes.rend(); ++iter)
	{
		if ((*iter)->HitTest(Point(point.x, point.y)) != 0)
		{
			(*iter)->Select(true);
			break;
		}
	}
}

void CSelectTool::OnMouseMove(UINT nFlags, CPoint point)
{
}

std::shared_ptr<CShape> CSelectTool::GetShape()
{
	return shared_ptr<CShape>();
}
