#ifndef CLASSIFIER__
#define CLASSIFIER__
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <string>
#include <iostream>
class Detector{
    public:
    std::string filePath = std::string("/usr/share/opencv/lbpcascades/lbpcascade_frontalface.xml");
    cv::CascadeClassifier classifier;
    cv::Point center;
    public:
    Detector();
    Detector(std::string path);
    cv::Point getCenter();
    void detect(cv::Mat& img, double scale);
};


#endif