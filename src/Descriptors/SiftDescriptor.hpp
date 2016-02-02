#ifndef SiftDESCRIPTOR
#define SiftDESCRIPTOR

#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <vector>
#include "DescriptorBase.hpp"

using namespace cv;

class SiftDescriptor : public DescriptorBase 
{
	private:
		vector<KeyPoint> _keyPoints;
	public:
		SiftDescriptor();
		virtual void compute(const Mat &image);
		virtual string getData() const;
		virtual void setData(string data) const;
		virtual const vector<KeyPoint>& getKeyPoints() const;
};

#endif