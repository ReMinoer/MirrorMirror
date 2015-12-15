#include <fstream>
#include "Indexer.hpp"

#define DESCRIPTOR_DATA_END "---"

using namespace std;

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
		
		TDescriptor descriptor = _factory();
		descriptor.compute(image);
		_descriptors.insert(std::pair<string, TDescriptor>(filename, descriptor));
	}
}

void Indexer::save(const string filename) const
{
	ofstream file;
	file.open(filename);
	
	for (map<string, TDescriptor>::const_iterator it = _descriptors.begin(); it != _descriptors.end(); it++)
	{
		string filename = it->first;
		TDescriptor descriptor = it->second;
		
		file << filename << endl;
		file << descriptor.getData() << endl;
		file << DESCRIPTOR_DATA_END << endl;
	}
	
	file.close();
}

void Indexer::load(const string filename)
{
	ifstream file;
	file.open(filename);
	
	string currentData;
	while (!file.eof())
	{
		char line[LINE_SIZE];
		file.getLine(line, LINE_SIZE);
		
		if (strstr(line, DESCRIPTOR_DATA_END))
		{
			TDescriptor descriptor = _factory();
			descriptor.setData(currentData);
			currentData = "";
		}
		else
			currentData += line + std::endl;
	}
	
	file.close();
}