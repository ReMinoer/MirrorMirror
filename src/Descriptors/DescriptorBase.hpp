#ifndef DESCRIPTORBASE
#define DESCRIPTORBASE

#include "../IDescriptor.hpp"

class DescriptorBase : public IDescriptor 
{
	public:
		virtual void compute(const Mat &image) = 0;
		virtual string getData() const = 0;
		virtual void setData(string data) const = 0;
		virtual void save(const string filename) const;
		virtual void load(const string filename);
};

#endif