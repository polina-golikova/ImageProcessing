#ifndef IMAGEPROCESSINGAPPLICATION_IMAGE_H
#define IMAGEPROCESSINGAPPLICATION_IMAGE_H

#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

class Image {
private:
    double height, width;
    string path;
    Mat* newImg;
    Mat* ogImg;
public:
    Image(string filePath);
    ~Image();
    double getHeight();
    double getWidth();
    void displayOgImg();
    void displayImg();
    void makeGray();
    void makeRGB();
    Mat originalImg();
    void saveImage();
};


#endif //IMAGEPROCESSINGAPPLICATION_IMAGE_H
