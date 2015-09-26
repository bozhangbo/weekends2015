#pragma once

#include <vector>
#include <complex>

struct Component
{
	double m0;
	double t2;
	double freq;

	Component(double i_m0, double i_t2, double i_freq) : m0(i_m0), t2(i_t2), freq(i_freq) {};
};

class CMrSimulator
{
public:
	CMrSimulator();
	virtual ~CMrSimulator();

	bool AddComponent(double m0, double t2, double freq);
	std::vector<std::complex<double>> GenerateData(const std::vector<double>& time);

	std::vector<Component> _components;
};

