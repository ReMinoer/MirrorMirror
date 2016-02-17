#include "SiftDescriptor.hpp"

SiftDescriptor::SiftDescriptor()
{
	std::vector<KeyPoint> _keyPoints();
}

void SiftDescriptor::compute(const Mat &image)
{
	SIFT descri();
	descri()(image,cv::noArray(),_keyPoints,cv::noArray());
}

string SiftDescriptor::getData() const
{
	stringstream dataKeyPoints;
	dataKeyPoints << _keyPoints.size() << ";";
	for(int i=0;i<_keyPoints.size();i++)
	{
		dataKeyPoints << _keyPoints[i].pt.x << "," << _keyPoints[i].pt.y << "," << _keyPoints[i].size << ";";
	}
	//dataKeyPoints << "!";
	return dataKeyPoints.str();
}

void SiftDescriptor::setData(string data) 
{
	_keyPoints.clear();
	stringstream dataKeyPoints(data);
	int nbPoints;
	dataKeyPoints >> nbPoints >> ";";
	for (int i = 0; i < nbPoints; i++)
	{
		float x, y, size;
		dataKeyPoints >> x >> "," >> y >> "," >> size >> ";";
		_keyPoints.push_back(KeyPoint(x,y,size));
/*
string dataS = data.substr(maPos,data.find(";"));
		_keyPoints.push_back(dataS);
		maPos=data.find(";")+1;
*/
	}
}

