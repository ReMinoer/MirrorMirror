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

class Indexer : public IIndexer
{
	typedef IDescriptor* (*DescriptorFactory) ();

	private:
		DescriptorFactory _factory;
		map<string, IDescriptor*> _descriptors;
	public:
		Indexer(DescriptorFactory factory);
		virtual void generate(const map<string, Mat> &images);
		virtual void save(const string filename) const;
		virtual void load(const string filename);
		virtual Mat computeMatrix();
		virtual IDescriptor* buildDescriptor(Mat& image);
};

#endif