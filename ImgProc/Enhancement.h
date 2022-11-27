#ifndef IMAGEPROCESSINGAPPLICATION_ENHANCEMENT_H
#define IMAGEPROCESSINGAPPLICATION_ENHANCEMENT_H

#include <iostream>
#include "Image.h"

using namespace cv;
using namespace std;

class Enhancement {
public:
    Enhancement(Mat *newImg);
    ~Enhancement();
    void histogramEquilization();
    void lowPassFilter();
    void highPassFilter();
private:
    Image *img;
};


#endif //IMAGEPROCESSINGAPPLICATION_ENHANCEMENT_H
