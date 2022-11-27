#include "Enhancement.h"

Enhancement::Enhancement(Mat *newImg)
{
    img = newImg;
}

~Enhancement::Enhancement(){}

void Enhancement::histogramEquilization()
{
    equalizeHist(img.getImg(), img.getImg());
}

void Enhancement::lowPassFilter()
{
    kern = ones
}

void Enhancement::highPassFilter()
{

}
