#pragma once
#include "Tool.h"
#include <memory>

class CRectangle;

class CRectangleTool :
	public CTool
{
public:
	CRectangleTool();
	virtual ~CRectangleTool();
	virtual void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnMouseMove(UINT nFlags, CPoint point);
	virtual std::shared_ptr<CShape> GetShape();

private:
	std::shared_ptr<CRectangle> _rect;
	CPoint _down_point;
};


