#include "stdafx.h"
#include "Tool.h"


CTool::CTool()
{
}


CTool::~CTool()
{
}

void CTool::SetColor(Gdiplus::Color color)
{
	_color = color;
}

Gdiplus::Color CTool::GetColor() const
{
	return _color;
}
