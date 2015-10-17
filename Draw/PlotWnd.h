#pragma once

#include <vector>
#include <memory>
// CPlotWnd

class CDataSeries
{
public:
	bool SetData(const std::vector<double>& x, const std::vector<double>& y);
	const std::vector<double>& GetX() const;
	const std::vector<double>& GetY() const;

	std::pair<double, double> GetMinMaxX() const;
	std::pair<double, double> GetMinMaxY() const;

	void SetColor(Gdiplus::Color color);
	Gdiplus::Color GetColor() const;

private:
	std::vector<double> _x;
	std::vector<double> _y;
	Gdiplus::Color _color;
};

class CPlotWnd : public CWnd
{
	DECLARE_DYNAMIC(CPlotWnd)

public:
	CPlotWnd();
	virtual ~CPlotWnd();

	bool AddData(const std::vector<double>& x, const std::vector<double>& y, Gdiplus::Color color);
protected:
	DECLARE_MESSAGE_MAP()

	afx_msg void OnPaint();

	std::pair<double, double> GetXRange();
	std::pair<double, double> GetYRange();

	std::vector<double> CoordinateTransform(double source_min, double source_max,
		double dest_min, double dest_max, const std::vector<double> & source);

	void DrawLines(Gdiplus::Graphics& graphics,
		const std::vector<double>& x,
		const std::vector<double>& y,
		Gdiplus::Color color);

	std::vector<std::shared_ptr<CDataSeries>> _data_series;
};


