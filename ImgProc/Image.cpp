#include "Image.h"

Image::Image(std::string filePath)
{
    path = filePath;
    // Read the image file
    *ogImg = imread(filePath);

    // Check for failure
    if (ogImg->empty())
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Could not open or find the image.");
        messageBox.setFixedSize(500,200);
    }
    else
    {
        newImg = ogImg;
        height = ogImg->rows;
        width = ogImg->cols;
    }
    makeGray();
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

Mat* Image::getImg() { return newImg; }

void Image::saveImage()
{
    makeRGB();
    // writing the image to a defined location as JPEG
    bool check = imwrite("..path\\MyImage.jpg", *newImg);

    // if the image is not saved
    if (check == false) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Failed to save image.");
        messageBox.setFixedSize(500,200);
    }
}

void Image::makeGray()
{
    cvtColor(*newImg, *newImg, COLOR_BRG2GRAY);
}

void Image::makeRGB()
{
    cvtColor(*newImg, *newImg, COLOR_GRAY2BRG);
}
