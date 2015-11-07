#pragma once
#include "Tool.h"
#include <memory>

class CEllipse;

class CEllipseTool :
	public CTool
{
public:
	CEllipseTool();
	virtual ~CEllipseTool();

	virtual void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnMouseMove(UINT nFlags, CPoint point);
	virtual std::shared_ptr<CShape> GetShape();

private:
	std::shared_ptr<CEllipse> _ellipse;
};

