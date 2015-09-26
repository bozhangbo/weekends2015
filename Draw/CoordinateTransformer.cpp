#include "stdafx.h"
#include "CoordinateTransformer.h"


CoordinateTransformer::CoordinateTransformer()
{
}


CoordinateTransformer::~CoordinateTransformer()
{
}

std::vector<double> CoordinateTransformer::CoordinateTransform(double source_min,
	double source_max,
	double dest_min,
	double dest_max,
	const std::vector<double>& source)
{
	std::vector<double> output(source.size());

	double a = (dest_max - dest_min) / (source_max - source_min);
	double b = -source_min * a + dest_min;

	for (unsigned int i = 0; i < source.size(); ++i)
	{
		output[i] = a * source[i] + b;
	}

	return output;
}