#ifndef INDEXER
#define INDEXER

#include <opencv2/core/core.hpp>
#include <string>
#include <fstream>
#include "IIndexer.hpp"

using namespace std;
using namespace cv;

#define DESCRIPTOR_DATA_END "---"
#define LINE_SIZE 99999

template<typename TDescriptor>
class Indexer : public IIndexer
{
	typedef TDescriptor (*DescriptorFactory) ();

	private:
		DescriptorFactory _factory;
		map<string, TDescriptor> _descriptors;
	public:
		Indexer(DescriptorFactory factory);
		virtual void generate(const map<string, Mat> &images);
		virtual void save(const string filename) const;
		virtual void load(const string filename);
};

#endif

template<typename TDescriptor>
Indexer<TDescriptor>::Indexer(DescriptorFactory factory)
	: _factory(factory)
{
}
		
template<typename TDescriptor>
void Indexer<TDescriptor>::generate(const map<string, Mat> &images)
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

template<typename TDescriptor>
void Indexer<TDescriptor>::save(const string filename) const
{
	ofstream file;
	file.open(filename.c_str());
	
	for (typename map<string, TDescriptor>::const_iterator it = _descriptors.begin(); it != _descriptors.end(); it++)
	{
		string filename = it->first;
		TDescriptor descriptor = it->second;
		
		file << filename << endl;
		file << descriptor.getData() << endl;
		file << DESCRIPTOR_DATA_END << endl;
	}
	
	file.close();
}

template<typename TDescriptor>
void Indexer<TDescriptor>::load(const string filename)
{
	ifstream file;
	file.open(filename.c_str());
	
	stringstream currentData;
	while (!file.eof())
	{
		char line[LINE_SIZE];
		file.getline(line, LINE_SIZE);
		
		if (strstr(line, DESCRIPTOR_DATA_END))
		{
			TDescriptor descriptor = _factory();
			descriptor.setData(currentData.str());
			currentData.clear();
		}
		else
		{
			currentData << line << std::endl;
		}
	}
	
	file.close();
}