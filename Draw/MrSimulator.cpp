#include "stdafx.h"
#include "MrSimulator.h"


CMrSimulator::CMrSimulator()
{
}


CMrSimulator::~CMrSimulator()
{
}

std::vector<std::complex<double>> CMrSimulator::GenerateData(
	const std::vector<double>& time)
{
	const double PI = 3.1415926535897932384626433832795;

	std::vector<std::complex<double>> output(time.size(), 0);
	std::complex<double> I(0, 1);

	for (auto component = _components.begin(); component != _components.end(); ++component)
	{
		for (unsigned int i = 0; i < time.size(); ++i)
		{
			output[i] += component->m0 * exp(-time[i] / component->t2) * exp(I * 2.0 * PI * component->freq * time[i]);
		}
	}

	return output;
}

bool CMrSimulator::AddComponent(double m0, double t2, double freq)
{
	if (m0 <= 0 || t2 <= 0)
	{
		return false;
	}

	Component component(m0, t2, freq);
	_components.push_back(component);

	return true;
}
