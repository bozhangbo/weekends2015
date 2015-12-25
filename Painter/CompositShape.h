#pragma once
#include "Shape.h"
#include <vector>
#include <memory>
#include <gdiplus.h>

class CCompositShape :
	public CShape
{
public:
	CCompositShape();
	virtual ~CCompositShape();

	bool AddShape(std::shared_ptr<CShape> shape);
	virtual void Draw(Gdiplus::Graphics& graphics) override;

	virtual void Save(CArchive& ar) override;

	virtual void Load(CArchive& ar) override;

	virtual int HitTest(const Gdiplus::Point& point) override;

	virtual void OnSetRect() override;

	void UpdateRelativePostions();
private:
	std::vector<std::shared_ptr<CShape>> _children;
	std::vector<Gdiplus::RectF> _relative_postions;
};

