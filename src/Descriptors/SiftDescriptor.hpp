#ifndef SiftDESCRIPTOR
#define SiftDESCRIPTOR

#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include </share/esir3/opencv-2.4.9/include/opencv2/nonfree/features2d.hpp>
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
