#ifndef MIRRORMIRRORENGINE
#define MIRRORMIRRORENGINE

using namespace std;

class MirrorMirrorEngine
{
	private:
		IIndexer* _indexer;
	public:
		MirrorMirrorEngine(IIndexer& indexer);
		Mat* search(const Mat &request) const;
		const IIndexer& getIndexer() const;
		void setIndexer(const IIndexer& indexer);
};

#endif