#include <fstream>
#include "DescriptorBase.hpp"

#define LINE_SIZE 99999

void DescriptorBase::save(const string filename) const
{
	ofstream file;
	file.open(filename);
	
	file << getData();
	
	file.close();
}

void DescriptorBase::load(const string filename)
{
	ifstream file;
	file.open(filename);
	string data;
	
	while (!file.eof())
	{
		char line[LINE_SIZE];
		file.getLine(line, LINE_SIZE);
		data += line + std::endl;
	}
		
	setData(data);
	file.close();
}