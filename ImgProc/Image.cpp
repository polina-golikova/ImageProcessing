#include "Image.h"

Image::Image(std::string filePath)
{
    path = filePath;
    // Read the image file
    *ogImg = imread(filePath);

    // Check for failure
    if (ogImg->empty())
    {
        std::cout << "Could not open or find the image" << std::endl;
    }
    else
    {
        newImg = ogImg;
        height = ogImg->rows;
        width = ogImg->cols;
    }
}

Image::~Image() {}

void Image::displayImg()
{
    // show image
    imshow("Image", *newImg);

    // Wait for any keystroke
    waitKey(0);
}

void Image::displayOgImg()
{
    // show image
    cv::imshow("Image", *ogImg);

    // Wait for any keystroke
    waitKey(0);
}

double Image::getHeight() { return height; }

double Image::getWidth() { return width; }

void Image::saveImage()
{
    // writing the image to a defined location as JPEG
    bool check = imwrite("..path\\MyImage.jpg", *newImg);

    // if the image is not saved
    if (check == false) {
        std::cout << "Saving the image, FAILED" << std:: endl;
    }
}

void Image::makeGray()
{
    Mat* grayImage;
    cvtColor(*newImg, *grayImage, COLOR_RGB2GRAY);
    newImg = grayImage;
}

void Image::makeRGB()
{
    Mat* colorImage;
    cvtColor(*newImg, *colorImage, COLOR_GRAY2RGB);
    newImg = colorImage;
}
