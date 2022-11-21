#include "Image.h"

Image::Image(string filePath)
{
    path = filePath;
    // Read the image file
    Mat ogImg = imread(filePath);

    // Check for failure
    if (ogImg.empty())
    {
        cout << "Could not open or find the image" << endl;
    }
    else
    {
        newImg = &ogImg;
        height = ogImg.rows;
        width = ogImg.cols;
    }
}

Image::~Image() {}

void Image::displayImg()
{
    // show image
    imshow("Image", &newImg);

    // Wait for any keystroke
    waitKey(0);
}

void Image::displayOgImg()
{
    // show image
    imshow("Image", &ogImg);

    // Wait for any keystroke
    waitKey(0);
}

double Image::getHeight() { return height; }

double Image::getWidth() { return width; }

Mat Image::originalImg() { return &ogImg; }

void Image::saveImage()
{
    // writing the image to a defined location as JPEG
    bool check = imwrite("..path\\MyImage.jpg", newImg);

    // if the image is not saved
    if (check == false) {
        cout << "Saving the image, FAILED" << endl;
    }

}

void Image::makeGray()
{
    Mat grayImage = cvtColor(newImg, COLOR_RGR2GRAY);
    newImg = &grayImage;
}

void Image::makeRGB()
{
    Mat colorImage = cvtColor(newImg, COLOR_GRAY2RGB);
    newImg = &colorImage;
}
