#include "Image.h"
#include <QMessageBox>

Image::Image(std::string filePath)
{
    path = filePath;
    // Read the image file
    Mat src = imread(filePath);
    ogImg = &src;
    // Check for failure
    if (ogImg->empty())
    {
        // Show error window if error occured during input
        QMessageBox messageBox;
        messageBox.critical(0, "Error","Could not open or find the image.");
        messageBox.setFixedSize(500, 200);
    }
    else
    {
        // Save images, set height and width
        newImg = new Mat;
        *newImg = *ogImg;
        ogImg = new Mat;
        *ogImg = *newImg;
        height = ogImg->rows;
        width = ogImg->cols;
    }
    makeGray();
}

Image::~Image()
{
    delete newImg;
    delete ogImg;
}

void Image::displayImg() {
  // show image
  std::string title = "Image";
  cv::imshow(title, *newImg);
}

void Image::displayOgImg()
{
    // show image
    cv::imshow("Original Image", *ogImg);
}

void Image::reset()
{
    newImg = new Mat;
    *newImg = *ogImg;
}

// getters for height and width
double Image::getHeight() { return height; }

double Image::getWidth() { return width; }

void Image::saveImage()
{
    // Undo grayscale on img
    makeRGB();
    // writing the image to a defined location as JPEG
    bool check = imwrite("..path\\MyImage.jpg", *newImg);

    // if the image is not saved
    if (check == false) {
        // Show error window if error occured during output
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Failed to save image.");
        messageBox.setFixedSize(500,200);
    }
}

void Image::makeGray()
{
    // Make RGB image grayscale
    cvtColor(*newImg, *newImg, COLOR_BGR2GRAY);
}

void Image::makeRGB()
{
    // Make grayscale image RGB
    cvtColor(*newImg, *newImg, COLOR_GRAY2BGR);
}
