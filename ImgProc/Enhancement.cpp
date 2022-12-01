#include "Enhancement.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

Enhancement::Enhancement(Image *newImg)
{
    img = newImg;
}

Enhancement::~Enhancement()
{
    // Deallocate memory
    delete img;
}

void Enhancement::histogramEquilization()
{
    equalizeHist( *img->newImg, *img->newImg );
}

void Enhancement::lowPassFilter()
{
    Mat dst;
    GaussianBlur( *img->newImg, dst, Size(1, 1), 0 );
    *img->newImg = dst;
}

void Enhancement::highPassFilter()
{
    Mat dst;
    GaussianBlur( *img->newImg, dst, Size(1, 1), 0 );
    *img->newImg = *img->newImg - dst;
}
