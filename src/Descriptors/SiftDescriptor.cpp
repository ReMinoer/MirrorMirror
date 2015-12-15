#include "SiftDescriptor.hpp"

SiftDescriptor::SiftDescriptor()
{
}

void SiftDescriptor::compute(const Mat &image)
{
	
}

string SiftDescriptor::getData() const
{
	return "";
}

void SiftDescriptor::setData(string data) const
{
	
}

const SiftDescriptor::vector<KeyPoint>& getKeyPoints() const
{
	return _keyPoints;
}