#ifndef CLASSIFIER__
#define CLASSIFIER__
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <string>
#include <iostream>
/*! This class takes care of detecting faces in each frame and updating its state accordingly */
class Detector{
    public:
    std::string filePath = std::string("/usr/share/opencv/lbpcascades/lbpcascade_frontalface.xml"); /*!< Cascade classifier path */
    cv::CascadeClassifier classifier;/*!< Cascade classifier to be used */
    cv::Point center;/*!< Detected face's center */
    public:
    Detector();/*!< Default constructor */
    Detector(std::string path);/*!< Initializes cacade path */
    cv::Point getCenter();/*!< Returns detected face's center */
    void detect(cv::Mat& img, double scale);/*!< Processes a frame (img), scaling it (scale) */
};


#endif