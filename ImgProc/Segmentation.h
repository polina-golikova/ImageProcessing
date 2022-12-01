#ifndef IMAGEPROCESSINGAPPLICATION_SEGMENTATION_H
#define IMAGEPROCESSINGAPPLICATION_SEGMENTATION_H

#include <iostream>
#include "Image.h"

using namespace cv;
using namespace std;

class Segmentation {
public:
    Segmentation(Image *newImg);
    ~Segmentation();
    void gauss(uint32_t);
    void thresh(uint32_t);
    void kirsch(uint32_t);
    void prewitt(uint32_t);
    void sobel(uint32_t);
    void watershed();
    void dialation(uint32_t);
    void erosion(uint32_t);

private:
    Image *img;
};


#endif //IMAGEPROCESSINGAPPLICATION_SEGMENTATION_H
