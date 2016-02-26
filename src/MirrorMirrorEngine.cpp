#include "opencv2/features2d/features2d.hpp"
#include "MirrorMirrorEngine.hpp"

MirrorMirrorEngine::MirrorMirrorEngine(IIndexer& indexer)
	: _indexer(&indexer)
{
}

void MirrorMirrorEngine::search(const Mat& imageRequest, std::vector<cv::Mat> & images) const
{
	//std::map<std::basic_string<char>, cvflann::any> params;
	cv::flann::Index index(_indexer->computeMatrix(), cv::flann::KDTreeIndexParams(4));
	
	vector<int> indices;
	vector<float> dists;
	double radius = 5.0;
	int maxResult = 5;
	index.radiusSearch(_indexer->buildDescriptor(imageRequest)->getVec3f(), indices, dists, radius, maxResult);
	string filename = _indexer->getPath(indices[0]);
	
	Mat image;
  image = imread(filename, CV_LOAD_IMAGE_COLOR);
            
  if (!image.data)
  {
      cout << filename << "can't be find or open" << std::endl;
  }
  else
  	images.push_back(image);
}

const IIndexer& MirrorMirrorEngine::getIndexer() const
{
	return *_indexer;
}

void MirrorMirrorEngine::setIndexer(const IIndexer& indexer)
{
	*_indexer = indexer;
}
