#include "Segmentation.h"

Segmentation::Segmentation(Mat *newImg)
{
    img = newImg;
}

~Segmentation::Segmentation()
{
    // Deallocate memory
    delete img;
}

void Segmentation::threshold(uint32_t max)
{
    threshold( img->newImg, img->newImg, max, 255, THRESH_BINARY );
}

void Segmentation::kirsch()
{

}

void Segmentation::prewitt()
{

}

void Segmentation::sobel()
{

}

void Segmentation::watershed()
{

}

void Segmentation::dialation()
{

}

void Segmentation::erosion()
{

}

