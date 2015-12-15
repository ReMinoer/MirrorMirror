#ifndef IINDEXER
#define IINDEXER

#include <opencv2/core/core.hpp>
#include <string>

using namespace std;
using namespace cv;

class IIndexer
{
	public:
		virtual void generate(const map<string, Mat> &images) = 0;
		virtual void save(const string filename) const = 0;
		virtual void load(const string filename) = 0;
};

#endif
