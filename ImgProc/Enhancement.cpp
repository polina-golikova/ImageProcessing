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

void Enhancement::lowPassFilter(uint32_t kern)
{
    Mat dst;
    blur(*img->newImg, dst, Size(9, 9), Point(-1, -1), BORDER_DEFAULT);
    *img->newImg = dst;
}

void Enhancement::highPassFilter(uint32_t kern)
{
    Mat dst;
    blur(*img->newImg, dst, Size(9, 9), Point(-1, -1), BORDER_DEFAULT);
    addWeighted(*img->newImg, 1.5, dst, -0.5, 0, *img->newImg);
}
