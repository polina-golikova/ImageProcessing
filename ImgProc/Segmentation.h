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
    void thresh(uint32_t);
    void kirsch(uint32_t kern);
    void prewitt(uint32_t kern);
    void sobel(uint32_t kern);
    void watershed();
    void dialation(uint32_t kern);
    void erosion(uint32_t kern);

private:
    Image *img;
};


#endif //IMAGEPROCESSINGAPPLICATION_SEGMENTATION_H
