#include "Segmentation.h"

Segmentation::Segmentation(Mat *newImg)
{
    img = newImg;
}
~Segmentation::Segmentation()
{
    delete img;
}
