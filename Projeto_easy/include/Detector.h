#ifndef CLASSIFIER__
#define CLASSIFIER__
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <string>
#include <iostream>
#include <dlib/opencv.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#define NEXTCANAL 1
#define PREVCANAL 2
#define MAISVOLUME 3
#define MENOSVOLUME 4
/*! This class takes care of detecting faces in each frame and updating its state accordingly */
class Detector{
    public:
    std::string filePath = std::string("/usr/share/opencv/lbpcascades/lbpcascade_frontalface.xml"); /*!< Landmark feature detector path  */
    unsigned char mSignal;/*!< Signal to be sent through socket */
    dlib::frontal_face_detector detector; /*!< Dlib's face detection algorithm */
    dlib::shape_predictor pose_model; /*!< Landmark detector pose-model (68 points mesh) */

    public:
    Detector();/*!< Default constructor */
    Detector(std::string path);/*!< Initializes cacade path */
    void detect(cv::Mat& img);/*!< Detects faces in frame */
    uint8_t getSignal();/*!< Returns signal */
};
#endif