#ifndef SiftDESCRIPTOR
#define SiftDESCRIPTOR

#include <opencv2/core/core.hpp>
#include <vector>
#include "DescriptorBase.hpp"

using namespace cv;

class SiftDescriptor : public DescriptorBase 
{
	public:
		SiftDescriptor();
		virtual void compute(const Mat &image);
		virtual string getData() const;
		virtual void setData(string data) ;
};

#endif
