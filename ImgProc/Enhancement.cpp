#include "Enhancement.h"

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
    equalizeHist(img->newImg, img->newImg);
}

void Enhancement::lowPassFilter()
{
    Mat *dst = img->newImg->clone();
    img->newImg = GaussianBlur(img->newImg, dst, Size(2, 2), 0, 0);
    delete dst;
}

void Enhancement::highPassFilter()
{
    Mat *dst = img->newImg->clone();
    img->newImg = img->newImg - GaussianBlur(img->newImg, dst, Size(2, 2), 0, 0);
    delete dst;
}
