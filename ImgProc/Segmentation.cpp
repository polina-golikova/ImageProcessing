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

void Segmentation::gauss(uint32_t kern)
{
    Mat dst;
    GaussianBlur(*img->newImg, dst, Size(kern, kern), 0);
    *img->newImg = dst;
}

void Segmentation::sobel(uint32_t kern)
{
    Mat dst1, dst2;
    Sobel(*img->newImg, dst1, CV_8U, 1, 0, kern);
    Sobel(*img->newImg, dst2, CV_8U, 0, 1, kern);
    *img->newImg = dst1 + dst2;
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

