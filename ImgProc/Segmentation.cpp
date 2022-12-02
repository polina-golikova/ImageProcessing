#include "Segmentation.h"

//  Segmentation: allocates memory, sets new Image obj
//
//  Input:  Image - new image object
//  Output:
//
Segmentation::Segmentation(Image *newImg)
{
    img = newImg;
}

//  ~Segmentation: frees memory
//
//  Input:
//  Output:
//
Segmentation::~Segmentation()
{
    // Deallocate img pointer
    delete img;
}

//  thresh: binary filter, True or Fale (dark or white) depending on threshold value
//
//  Input:  uint32_t - threshold value, anything below this is 0 or white, anything above is black
//  Output:
//
void Segmentation::thresh(uint32_t max)
{
    Mat dst;
    threshold(*img->newImg, dst, max, 255, THRESH_BINARY);
    *img->newImg = dst;
}

//  gauss: gaussian blur filter
//
//  Input:  uint32_t - kernel size to do convolution with
//  Output:
//
void Segmentation::gauss(uint32_t kern)
{
    Mat dst;
    GaussianBlur(*img->newImg, dst, Size(kern, kern), 0);
    *img->newImg = dst;
}

//  sobel: segments image, distinguishing borders
//
//  Input:  uint32_t - kernel size to do convolution with
//  Output:
//
void Segmentation::sobel(uint32_t kern)
{
    Mat dst1, dst2;
    Sobel(*img->newImg, dst1, CV_8U, 1, 0, kern);
    Sobel(*img->newImg, dst2, CV_8U, 0, 1, kern);
    *img->newImg = dst1 + dst2;
}

//  dialation: expands whites and borders
//
//  Input:  uint32_t - kernel size to do convolution with
//  Output:
//
void Segmentation::dialation(uint32_t kern)
{
    Mat dst;
    Mat element = getStructuringElement( MORPH_RECT,
                         Size( 2*kern + 1, 2*kern+1 ),
                         Point( kern, kern ) );
    dilate(*img->newImg, dst, element, Point(-1, -1), 1);
    *img->newImg = dst;
}

//  erosion: slims or trims away at whites
//
//  Input:  uint32_t - kernel size to do convolution with
//  Output:
//
void Segmentation::erosion(uint32_t kern)
{
    Mat dst;
    Mat element = getStructuringElement( MORPH_RECT,
                         Size( 2*kern + 1, 2*kern+1 ),
                         Point( kern, kern ) );
    erode(*img->newImg, dst, element, Point(-1, -1), 1);
    *img->newImg = dst;
}

