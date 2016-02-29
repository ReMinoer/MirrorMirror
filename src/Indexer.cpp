#include <opencv2/core/core.hpp>
#include <string>
#include <iostream>
#include "Indexer.hpp"

using namespace std;
using namespace cv;

Indexer::Indexer(DescriptorFactory factory)
	: _factory(factory)
{
}

void Indexer::generate(const map<string, Mat> &images)
{
	for (map<string, Mat>::const_iterator it = images.begin(); it != images.end(); it++)
	{
		string filename = it->first;
		Mat image = it->second;
		
		IDescriptor* descriptor = _factory();
		descriptor->compute(image);
		_descriptors.insert(std::pair<string, IDescriptor*>(filename, descriptor));
	}
}

void Indexer::save(const string filename) const
{
	ofstream file;
	file.open(filename.c_str());
	
	for (typename map<string, IDescriptor*>::const_iterator it = _descriptors.begin(); it != _descriptors.end(); it++)
	{
		string filename = it->first;
		IDescriptor* descriptor = it->second;
		
		file << filename << endl;
		file << descriptor->getData() << endl;
		file << DESCRIPTOR_DATA_END << endl;
	}
	
	file.close();
}

void Indexer::load(const string filename)
{
	ifstream file;
	file.open(filename.c_str());
	
	while (!file.eof())
	{
		char line[LINE_SIZE];
		string filename;
		string descriptorData;
		
		file.getline(line, LINE_SIZE);
		filename = line;
		
		file.getline(line, LINE_SIZE);
		descriptorData = line;
		
		file.getline(line, LINE_SIZE);
		
		IDescriptor* descriptor = _factory();
		descriptor->setData(descriptorData);
		_descriptors[filename] = descriptor;
	}
	
	file.close();
}

Mat Indexer::computeMatrix()
{
	std::cout << "ComputeMatrix: Begin"<<	std::endl;
	map<string, IDescriptor*>::iterator it = _descriptors.begin();
	int dimensions = it->second->size();
	Mat result(dimensions, (int)_descriptors.size(), CV_32FC3);
	for (int i = 0; i < dimensions; i++)
	{
		int j = 0;
		for (typename map<string, IDescriptor*>::const_iterator it = _descriptors.begin(); it != _descriptors.end(); it++)
		{
			//std::cout <<"i: " <<i<< ", j: "<<j<<std::endl;
			KeyPoint keyPoint = (*it->second)[i];
			result.at<Vec3f>(i, j) = Vec3f(keyPoint.pt.x, keyPoint.pt.y, keyPoint.size);
			j++;
		}
	}
	std::cout << "ComputeMatrix: End"<< std::endl;
	return result;
}

IDescriptor* Indexer::buildDescriptor(const Mat& image)
{
	IDescriptor* descriptor = _factory();
	descriptor->compute(image);
	return descriptor;
}

string Indexer::getPath(int indice)
{
	std::map<string,IDescriptor*>::iterator it;
	int i =0;
	for(it = _descriptors.begin();it != _descriptors.end();it++)
	{
		if(i=indice)
			return it->first;
		else
			i++;
	}
	return NULL;
}
