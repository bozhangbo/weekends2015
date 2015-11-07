#pragma once
#include "Tool.h"
#include <memory>

class CLine;

class CLineTool :
	public CTool
{
public:
	CLineTool();
	virtual ~CLineTool();

	virtual void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnMouseMove(UINT nFlags, CPoint point);
	virtual std::shared_ptr<CShape> GetShape();

private:
	std::shared_ptr<CLine> _line;
};

