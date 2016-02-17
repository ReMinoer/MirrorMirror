#ifndef DESCRIPTORBASE
#define DESCRIPTORBASE

#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include "../IDescriptor.hpp"

class DescriptorBase : public IDescriptor 
{
	protected:
		vector<KeyPoint> _keyPoints;
	public:
		virtual int size() const;
		virtual KeyPoint operator[] (int i) const;
		virtual void compute(const Mat &image) = 0;
		const virtual vector<KeyPoint>* getKeyPoints() const;
		virtual string getData() const = 0;
		virtual void setData(string data) = 0;
		virtual void save(const string filename) const;
		virtual void load(const string filename);
};

#endif
