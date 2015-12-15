#include "MirrorMirrorEngine.hpp"

MirrorMirrorEngine::MirrorMirrorEngine(IIndexer& indexer)
	: _indexer(&indexer)
{
}

Mat* MirrorMirrorEngine::search(const Mat& request) const
{
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
