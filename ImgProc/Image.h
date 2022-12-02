#ifndef IMAGEPROCESSINGAPPLICATION_IMAGE_H
#define IMAGEPROCESSINGAPPLICATION_IMAGE_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <string>

using namespace cv;

class Image {
private:
    double height, width;
    std::string path;
    Mat* ogImg;
public:
    Image(std::string);
    ~Image();
    double getHeight();
    double getWidth();
    void displayOgImg();
    void displayImg(std::string);
    void makeGray();
    void makeRGB();
    void saveImage(std::string);
    void reset();
    Mat* getImg();
    Mat* newImg;
};


#endif //IMAGEPROCESSINGAPPLICATION_IMAGE_H
