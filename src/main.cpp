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

IDescriptor* siftFactory()
{
    return new SiftDescriptor();
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
        if (strstr(ent->d_name, ".jpg"))
        {
            string imageFilename = imagesDirPath + ent->d_name;
            
            Mat image;
            image = imread(imageFilename, CV_LOAD_IMAGE_COLOR);
            
            if (!image.data)
            {
                cout << imageFilename << " can't be find or open" << std::endl;
                closedir (dir);
                return EXIT_FAILURE;
            }
            
            images.insert(std::pair<string, Mat>(imageFilename, image));
        }
    }
    
    IIndexer* indexer = new Indexer(&siftFactory);
    indexer->generate(images);
    indexer->save(imagesDirPath + INDEXER_FILENAME);
    
    closedir (dir);
    delete indexer;
    
    return EXIT_SUCCESS;
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
    
    IIndexer* indexer = new Indexer(&siftFactory);
    indexer->load(indexerDirPath + INDEXER_FILENAME);
    
    MirrorMirrorEngine engine = MirrorMirrorEngine(*indexer);
    std::vector<cv::Mat> images;
    engine.search(inputImage,images);
    
    namedWindow("Output", WINDOW_AUTOSIZE);
    imshow("Output", images[0]);

    delete indexer;
    waitKey(0);
    
    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    if (argc == 3 && strcmp(argv[1], "-index") == 0)
    {
        return index(argv[2]);
    }
    else if (argc == 4 && strcmp(argv[1], "-search") == 0)
    {
        return search(argv[2], argv[3]);
    }
    
    cout <<" Usage: MirrorMirror [-index imagesDirPath | -search inputImageFilename indexerDirPath]" << endl;
    return EXIT_FAILURE;
}
