#ifndef ICONTENTSEARCHENGINE
#define ICONTENTSEARCHENGINE

using namespace std;

class IContentSearchEngine
{
	public:
		virtual void search(const Mat &request, Mat &result) const = 0;
		virtual const IIndexer& getIndexer() const = 0;
		virtual void setIndexer(const IIndexer &indexer) = 0;
}

#endif
