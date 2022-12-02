#include "Segmentation.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

Segmentation::Segmentation(Image *newImg)
{
    img = newImg;
}

Segmentation::~Segmentation()
{
    // Deallocate memory
    delete img;
}

void Segmentation::thresh(uint32_t max)
{
    Mat dst;
    threshold(*img->newImg, dst, max, 255, THRESH_BINARY);
    *img->newImg = dst;
}

void Segmentation::kirsch(uint32_t kern)
{

}

void Segmentation::gauss(uint32_t kern)
{
    Mat dst;
    GaussianBlur(*img->newImg, dst, Size(kern, kern), 0);
    *img->newImg = dst;
}

void Segmentation::prewitt(uint32_t kern)
{

}

void Segmentation::sobel(uint32_t kern)
{

}

void Segmentation::watershed()
{

}

void Segmentation::dialation(uint32_t kern)
{
    Mat dst;
    Mat element = getStructuringElement( MORPH_RECT,
                         Size( 2*kern + 1, 2*kern+1 ),
                         Point( kern, kern ) );
    dilate(*img->newImg, dst, element, Point(-1, -1), 1);
    *img->newImg = dst;
}

void Segmentation::erosion(uint32_t kern)
{
    Mat dst;
    Mat element = getStructuringElement( MORPH_RECT,
                         Size( 2*kern + 1, 2*kern+1 ),
                         Point( kern, kern ) );
    erode(*img->newImg, dst, element, Point(-1, -1), 1);
    *img->newImg = dst;
}

