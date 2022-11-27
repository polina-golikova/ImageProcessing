#ifndef IMAGEPROCESSINGAPPLICATION_SEGMENTATION_H
#define IMAGEPROCESSINGAPPLICATION_SEGMENTATION_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include "Image.h"

using namespace cv;
using namespace std;

class Segmentation {
public:
    Segmentation(Mat *newImg);
    ~Segmentation();
private:
    Image *img;
};


#endif //IMAGEPROCESSINGAPPLICATION_SEGMENTATION_H
