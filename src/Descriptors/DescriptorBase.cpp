#include <fstream>
#include "DescriptorBase.hpp"

#define LINE_SIZE 99999

using namespace std;

int DescriptorBase::size() const
{
	return _keyPoints.size();
}

KeyPoint DescriptorBase::operator[] (int i) const
{
	return _keyPoints[i];
}

const vector<KeyPoint>* DescriptorBase::getKeyPoints() const
{
	return &_keyPoints;
}

const  vector<cv::Vec3f> DescriptorBase::getVec3f()
{
	vector<cv::Vec3f> keypoints;
	for(int i=0;i<_keyPoints.size();i++)
	{
		keypoints.push_back(Vec3f(_keyPoints[i].pt.x, _keyPoints[i].pt.y, _keyPoints[i].size));
	}
	return keypoints;
}

void DescriptorBase::save(const string filename) const
{
	ofstream file;
	file.open(filename.c_str());
	
	file << getData();
	
	file.close();
}

void DescriptorBase::load(const string filename)
{
	ifstream file;
	file.open(filename.c_str());
	stringstream data;
	
	while (!file.eof())
	{
		char line[LINE_SIZE];
		file.getline(line, LINE_SIZE);
		data << line << std::endl;
	}
		
	setData(data.str());
	file.close();
}
