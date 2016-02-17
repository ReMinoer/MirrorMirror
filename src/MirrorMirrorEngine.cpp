#include "opencv2/features2d/features2d.hpp"
#include "MirrorMirrorEngine.hpp"

MirrorMirrorEngine::MirrorMirrorEngine(IIndexer& indexer)
	: _indexer(&indexer)
{
}

Mat* MirrorMirrorEngine::search(const Mat& imageRequest) const
{
	cv::flann::LinearIndexParams params;
	//cv::flann::Index_<Vector3f> index(_indexer->computeMatrix(), params);
	
	//index.radiusSearch(_indexer.buildDescriptor().getKeyPoints(), vector<int>& indices, vector<float>& dists, float radius, const SearchParams& params)
	
	return NULL;
}

const IIndexer& MirrorMirrorEngine::getIndexer() const
{
	return *_indexer;
}

void MirrorMirrorEngine::setIndexer(const IIndexer& indexer)
{
	*_indexer = indexer;
}
