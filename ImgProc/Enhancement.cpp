#include "Enhancement.h"

//  Enhancement: allocates memory, sets new Image obj
//
//  Input:  Image - new image object
//  Output:
//
Enhancement::Enhancement(Image *newImg)
{
    img = newImg;
}

//  ~Enhancement: frees memory
//
//  Input:
//  Output:
//
Enhancement::~Enhancement()
{
    // Deallocate img pointer
    delete img;
}

//  histogramEquilization: balances out the grayscale histogram colors
//
//  Input:
//  Output:
//
void Enhancement::histogramEquilization()
{
    equalizeHist( *img->newImg, *img->newImg );
}

//  lowPassFilter: low pass filter blurs images, average blur filter
//
//  Input:  uint32_t - kernel size to do convolution with
//  Output:
//
void Enhancement::lowPassFilter(uint32_t kern)
{
    Mat dst;
    blur(*img->newImg, dst, Size(9, 9), Point(-1, -1), BORDER_DEFAULT);
    *img->newImg = dst;
}

//  highPassFilter: high pass filter sharpens images, subtracts average filter from original img
//
//  Input:  uint32_t - kernel size to do convolution with
//  Output:
//
void Enhancement::highPassFilter(uint32_t kern)
{
    Mat dst;
    blur(*img->newImg, dst, Size(9, 9), Point(-1, -1), BORDER_DEFAULT);
    addWeighted(*img->newImg, 1.5, dst, -0.5, 0, *img->newImg);
}

//  brightness: brightness makes images darker or brighter
//
//  Input:  uint32_t - brightness value to add or subtract from image
//  Output:
//
void Enhancement::brightness(int32_t b)
{
    Mat dst;
    img->newImg->convertTo(dst, -1, 1, b);
    *img->newImg = dst;
}

//  colorMap: applies color set to a grayscale img
//
//  Input:  Color enum value for a specific color map to apply
//  Output:
//
void Enhancement::colorMap(int cMap)
{
    Mat dst;
    applyColorMap(*img->newImg, dst, cMap);
    *img->newImg = dst;
}
