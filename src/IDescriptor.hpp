#ifndef IDESCRIPTOR
#define IDESCRIPTOR

#include <string>

using namespace std;

class IDescriptor 
{
	public:
		virtual void compute(const Mat &image) = 0;
		virtual string getData() const = 0;
		virtual void setData(string data) const = 0;
		virtual void save(const string filename) const = 0;
		virtual void load(const string filename) = 0;
};

#endif
