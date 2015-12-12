#pragma once
#include "Tool.h"
class CSelectTool :
	public CTool
{
public:
	CSelectTool();
	virtual ~CSelectTool();

	virtual void OnLButtonDown(UINT nFlags, CPoint point) override;
	virtual void OnMouseMove(UINT nFlags, CPoint point) override;

	virtual std::shared_ptr<CShape> GetShape() override;


};

