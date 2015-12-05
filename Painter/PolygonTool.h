#pragma once
#include "Tool.h"

class CPolygon;

class CPolygonTool :
	public CTool
{
public:
	CPolygonTool();
	virtual ~CPolygonTool();

	virtual void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnMouseMove(UINT nFlags, CPoint point);

	virtual void OnLButtonDoubleClick(UINT nFlags, CPoint point);

	virtual std::shared_ptr<CShape> GetShape();

protected:
	std::shared_ptr<CPolygon> _polygon;
};

