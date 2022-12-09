#include "Image.h"
#include <QMessageBox>
#include <filesystem>

//  Image: creates Image object to perform operations on
//
//  Input:  string - filepath to read image from
//  Output:
//
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
    // Convert image into grayscale
    makeGray();
}

//  ~Image: deallocates memory
//
//  Input:
//  Output:
//
Image::~Image()
{
    // free pointers
    delete newImg;
    delete ogImg;
}

//  displayImg: display modified image
//
//  Input:
//  Output:
//
void Image::displayImg(std::string commands) {
  // show image
  std::string title = "Image" + commands;
  imshow(title, *newImg);
}

//  displayOgImg: display original image
//
//  Input:
//  Output:
//
void Image::displayOgImg()
{
    // show image
    imshow("Original Image", *ogImg);
}

//  reset: resets modified image to the original image contents
//
//  Input:
//  Output:
//
void Image::reset()
{
    newImg = new Mat;
    *newImg = *ogImg;
}

//  getHeight/Width: getters for width and heigtht of image
//
//  Input:
//  Output: double - height and width of image
//
double Image::getHeight() { return height; }

double Image::getWidth() { return width; }

//  saveImage: saves image with modified title to project directory
//
//  Input:  string - modifier for image title to name, using operations that were performed
//  Output:
//
void Image::saveImage(std::string commands)
{
    // Undo grayscale on img
    makeRGB();

    std::string fileName = path.substr(path.find_last_of("/\\") + 1);
    std::string name = "images/" + fileName + commands + ".jpg";
    std::filesystem::path cwd = std::filesystem::current_path() / name;

    // writing the image to a defined location as JPEG
    bool check = imwrite(cwd.string(), *newImg);

    // if the image is not saved
    if (check == false) {
        // Show error window if error occured during output
        QMessageBox messageBox;
        messageBox.critical(0,"Error", "Failed to save image.");
        messageBox.setFixedSize(500,200);
    }
}


//  makeGray: converts RGB image into grayscale
//
//  Input:
//  Output:
//
void Image::makeGray()
{
    // Make RGB image grayscale
    cvtColor(*newImg, *newImg, COLOR_BGR2GRAY);
}

//  makeRGB: converts grayscale into 3 channel RGB image, not in color
//
//  Input:
//  Output:
//
void Image::makeRGB()
{
    cvtColor(*newImg, *newImg, COLOR_GRAY2BGR);
}
