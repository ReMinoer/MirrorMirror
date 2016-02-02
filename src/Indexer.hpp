#ifndef INDEXER
#define INDEXER

#include <opencv2/core/core.hpp>
#include <string>
#include "IIndexer.hpp"

using namespace std;
using namespace cv;

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
