#ifndef IINDEXER
#define IINDEXER

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>
#include "IDescriptor.hpp"

using namespace std;
using namespace cv;

class IIndexer
{
	public:
		virtual void generate(const map<string, Mat> &images) = 0;
		virtual void save(const string filename) const = 0;
		virtual void load(const string filename) = 0;
		virtual Mat computeMatrix() = 0;
		virtual string getPath(int indice)=0;
		virtual IDescriptor* buildDescriptor(const Mat& image) = 0;
};

#endif
