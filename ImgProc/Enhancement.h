#ifndef IMAGEPROCESSINGAPPLICATION_ENHANCEMENT_H
#define IMAGEPROCESSINGAPPLICATION_ENHANCEMENT_H

#include <iostream>
#include "Image.h"

using namespace cv;
using namespace std;

class Enhancement {
public:
    Enhancement(Image *newImg);
    ~Enhancement();
    void histogramEquilization();
    void lowPassFilter(uint32_t);
    void highPassFilter(uint32_t);
    void brightness(int32_t);
    void colorMap(int cMap);
private:
    Image *img;
};


#endif //IMAGEPROCESSINGAPPLICATION_ENHANCEMENT_H
