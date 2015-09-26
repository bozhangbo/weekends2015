#pragma once
#include <vector>
class CoordinateTransformer
{
public:
	CoordinateTransformer();
	~CoordinateTransformer();
	static std::vector<double> CoordinateTransform(double source_min,
		double source_max,
		double dest_min,
		double dest_max,
		const std::vector<double>& source);
};

