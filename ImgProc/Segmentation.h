#ifndef IMAGEPROCESSINGAPPLICATION_SEGMENTATION_H
#define IMAGEPROCESSINGAPPLICATION_SEGMENTATION_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include "Image.h"

using namespace cv;
using namespace std;

class Segmentation {
public:
    Segmentation(Image *newImg);
    ~Segmentation();
    void threshold(uint32_t);
    void kirsch();
    void prewitt();
    void sobel();
    void watershed();
    void dialation();
    void erosion();

private:
    Image *img;
};


#endif //IMAGEPROCESSINGAPPLICATION_SEGMENTATION_H
