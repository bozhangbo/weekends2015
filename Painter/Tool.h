#pragma once

#include <memory>
class CShape;

class CTool
{
public:
	CTool();
	virtual ~CTool();

	virtual void OnLButtonDown(UINT nFlags, CPoint point) = 0;
	virtual void OnMouseMove(UINT nFlags, CPoint point) = 0;

	virtual std::shared_ptr<CShape> GetShape() = 0;
};

