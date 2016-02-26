#ifndef IDESCRIPTOR
#define IDESCRIPTOR

#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <string>

using namespace std;
using namespace cv;

class IDescriptor 
{
	public:
		virtual int size() const = 0;
		virtual KeyPoint operator[] (int i) const = 0;
		virtual void compute(const Mat &image) = 0;
		virtual const vector<KeyPoint>* getKeyPoints() const = 0;
		const virtual vector<cv::Vec3f> getVec3f() = 0;
		virtual string getData() const = 0;
		virtual void setData(string data) = 0;
		virtual void save(const string filename) const = 0;
		virtual void load(const string filename) = 0;
};

#endif
