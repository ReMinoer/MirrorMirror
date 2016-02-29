#include <opencv2/features2d/features2d.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <iostream>
#include "SiftDescriptor.hpp"

SiftDescriptor::SiftDescriptor()
{
	std::vector<KeyPoint> _keyPoints();
}

void SiftDescriptor::compute(const Mat &image)
{
	int nbKeyPoints = 20;
	cv::SiftFeatureDetector detector(nbKeyPoints);
	detector.detect(image, _keyPoints);
	while(_keyPoints.size() > nbKeyPoints)
		_keyPoints.erase(_keyPoints.end());
}

string SiftDescriptor::getData() const
{
	stringstream dataKeyPoints;
	dataKeyPoints << _keyPoints.size() << " ";
	for(int i=0;i<_keyPoints.size();i++)
	{
		dataKeyPoints << _keyPoints[i].pt.x << " " << _keyPoints[i].pt.y << " " << _keyPoints[i].size << " ";
	}
	//dataKeyPoints << "!";
	return dataKeyPoints.str();
}

void SiftDescriptor::setData(string data) 
{
	_keyPoints.clear();
	stringstream dataKeyPoints(data);
	int nbPoints;
		
	dataKeyPoints >> nbPoints;
	cout <<nbPoints<<endl;
	for (int i = 0; i < nbPoints; i++)
	{
		double x, y, size;
		dataKeyPoints >> x;
 		dataKeyPoints >> y;
		dataKeyPoints >> size;
		//cout << x <<", " <<y <<", "<<size<<endl;
		_keyPoints.push_back(KeyPoint(x,y,size));
/*
string dataS = data.substr(maPos,data.find(";"));
		_keyPoints.push_back(dataS);
		maPos=data.find(";")+1;
*/
	}
}

