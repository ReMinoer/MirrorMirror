#ifndef IINDEXER
#define IINDEXER

#include <string>

using namespace std;

class IIndexer
{
	public:
		virtual void generate(const vector<string> &imageFilenames) = 0;
		virtual void save(const string filename) const = 0;
		virtual void load(const string filename) = 0;
}

#endif
