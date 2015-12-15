#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <dirent.h>
#include <map>

#include "IIndexer.hpp"
#include "IDescriptor.hpp"
#include "MirrorMirrorEngine.hpp"
#include "Indexer.hpp"
#include "Descriptors/SiftDescriptor.hpp"

using namespace cv;
using namespace std;

#define INDEXER_FILENAME "MirrorMirrorIndex.txt"

SiftDescriptor siftFactory()
{
    return SiftDescriptor();
}

int index(string imagesDirPath)
{
    map<string, Mat> images;
    
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(imagesDirPath.c_str())) == NULL)
    {
        cout << imagesDirPath << " directory can't be found" << std::endl;
        return EXIT_FAILURE;
    }
    
    while ((ent = readdir (dir)) != NULL)
    {
        if (strstr(ent->d_name, ".png"))
        {
            string imageFilename = imagesDirPath + ent->d_name;
            
            Mat image;
            image = imread(imageFilename, CV_LOAD_IMAGE_COLOR);
            
            if (!image.data)
            {
                cout << imageFilename << "can't be find or open" << std::endl;
                closedir (dir);
                return EXIT_FAILURE;
            }
            
            images.insert(std::pair<string, Mat>(imageFilename, image));
        }
    }
    
    IIndexer* indexer = new Indexer<SiftDescriptor>(&siftFactory);
    indexer->generate(images);
    indexer->save(imagesDirPath + INDEXER_FILENAME);
    
    closedir (dir);
    delete indexer;
}

int search(string inputImageFilename, string indexerDirPath)
{
    Mat inputImage;
    inputImage = imread(inputImageFilename, CV_LOAD_IMAGE_COLOR);

    if (!inputImage.data)
    {
        cout << inputImageFilename << "can't be find or open" << std::endl;
        return EXIT_FAILURE;
    }

    namedWindow("Input", WINDOW_AUTOSIZE);
    imshow("Input", inputImage);
    
    IIndexer* indexer = new Indexer<SiftDescriptor>(&siftFactory);
    indexer->load(indexerDirPath + INDEXER_FILENAME);
    
    MirrorMirrorEngine engine = MirrorMirrorEngine(*indexer);
    Mat* result = engine.search(inputImage);
    
    namedWindow("Output", WINDOW_AUTOSIZE);
    imshow("Output", *result);

    delete indexer;
    waitKey(0);
}

int main(int argc, char** argv)
{
    if (argv[1] == "-index" && argc == 3)
    {
        return index(argv[2]);
    }
    if (argv[1] == "-search" && argc == 4)
    {
        return search(argv[2], argv[3]);
    }
    
	cout <<" Usage: MirrorMirror [-index imagesDirPath | -search inputImageFilename indexerDirPath]" << endl;
    return -1;
}