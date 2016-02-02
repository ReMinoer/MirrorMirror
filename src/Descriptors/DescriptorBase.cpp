#include <fstream>
#include "DescriptorBase.hpp"

#define LINE_SIZE 99999

using namespace std;

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