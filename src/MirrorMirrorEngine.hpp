#ifndef MIRRORMIRRORENGINE
#define MIRRORMIRRORENGINE

#include "IIndexer.hpp"
#include "opencv2/flann/flann.hpp"

using namespace std;

class MirrorMirrorEngine
{
	private:
		IIndexer* _indexer;
	public:
		MirrorMirrorEngine(IIndexer& indexer);
		void search(const Mat &request, std::vector<cv::Mat> & images) const;
		const IIndexer& getIndexer() const;
		void setIndexer(const IIndexer& indexer);
};

#endif
