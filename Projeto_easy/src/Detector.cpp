#include "../include/Detector.h"
///////////////////////Helper functions////////////////////
//Transforms point into a space where every point lies inside a square of arbitrary side length
inline cv::Point transform(cv::Point& oldPoint, cv::Point& newOrigin, double ratio){
    cv::Point result(ratio*(oldPoint.x - newOrigin.x), ratio*(oldPoint.y - newOrigin.y));
    return result;
}
//Returns modulus of a point
inline double modulus(cv::Point& point){
    double m = std::sqrt(point.x*point.x + point.y*point.y);
    return m;
}
//Transforms and returns modulus
inline double normalizedDistance(cv::Point& oldVector,cv::Point faceCenter ,cv::Point& newOrigin, double ratio){
    cv::Point tmp = transform(oldVector, newOrigin, ratio) - faceCenter;
    return modulus(tmp);
}
//Convert from dlib's representation of a point into opencv's
inline cv::Point getCvPoint(dlib::point& p){
    cv::Point tmp(p.x(),p.y());
    return tmp;
}
//Convert from opencv's representation of a point into dlib's
inline dlib::point getDlibPoint(cv::Point& p){
    dlib::point point(p.x, p.y);
    return point;
}
///////////////////////////////////////////////////////////
Detector::Detector(std::string path) : filePath(path){
    //Initializes detector and deserializes data file in path
    try{
        detector = dlib::get_frontal_face_detector();
        dlib::deserialize(path.c_str()) >> pose_model;
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
}
Detector::Detector(){
    detector = dlib::get_frontal_face_detector();
    dlib::deserialize("../shape_predictor_68_face_landmarks.dat") >> pose_model;
}
uint8_t Detector::getSignal(){
    return mSignal;
}
void Detector::detect(cv::Mat& frame){
    //Convert Mat into an object that can be manipulated by dlib's algorithm
    dlib::cv_image<dlib::bgr_pixel> cimg(frame);
    std::vector<dlib::rectangle> faces = detector(cimg);
    std::vector<dlib::full_object_detection> shapes;
    //Fill shapes with face meshes in the current frame
    for(auto e : faces)
        shapes.push_back(pose_model(cimg, e));
    //If there are faces detected, do work
    if(!shapes.empty()){
       for(int i = 0; i<68 ; i++){
            //Show index of each point as text on the screen
            cv::Point p(shapes[0].part(i).x(), shapes[0].part(i).y());
            cv::circle( frame, p, 2, cv::Scalar(255,0,0), 2, 6, 0 );   
            cv::putText(frame,std::to_string(i),p+cv::Point(-5,-5), cv::FONT_HERSHEY_SIMPLEX, 0.2, cv::Scalar(255,0,0));   
        }
        //Get center of biggest face
        auto rect = shapes[0].get_rect();
        auto tmpCenter = dlib::center(rect);
        //New origin, previously top left of the screen
        cv::Point newOrigin(tmpCenter.x(), tmpCenter.y());
        //Ratio for transformations
        double ratio = 150.0/rect.width();
        //Get positions of every relevant point
        cv::Point center = getCvPoint(shapes[0].part(30));
        cv::Point right = getCvPoint(shapes[0].part(2));
        cv::Point left = getCvPoint(shapes[0].part(14));
        cv::Point bottom = getCvPoint(shapes[0].part(33));
        cv::Point faceCenter = transform(center, newOrigin, ratio);
        //Finding distance from each relevant point to the center piece (point 30)
        double rightDistance = normalizedDistance(right, faceCenter, newOrigin, ratio);
        double leftDistance = normalizedDistance(left, faceCenter, newOrigin, ratio);
        double bottomDistance = normalizedDistance(bottom, faceCenter, newOrigin, ratio);
        //Show lines and distances for debugging
        cv::line(frame, center, right, cv::Scalar(0,0,255));
        cv::putText(frame,std::to_string((int)rightDistance), right - cv::Point(10,5), cv::FONT_HERSHEY_SIMPLEX, 0.35, cv::Scalar(0,0,255));   
        cv::line(frame, center, left, cv::Scalar(0,0,255));
        cv::putText(frame,std::to_string((int)leftDistance),left + cv::Point(5,5), cv::FONT_HERSHEY_SIMPLEX, 0.35, cv::Scalar(0,0,255));   
        cv::line(frame, center, bottom, cv::Scalar(0,0,255));
        cv::putText(frame,std::to_string((int)bottomDistance),bottom + cv::Point(5,15), cv::FONT_HERSHEY_SIMPLEX, 0.35, cv::Scalar(0,0,255));   
        //Update signal accordingly
        if(rightDistance <= 50)
            mSignal = NEXTCANAL;
        else if(leftDistance <= 50)
            mSignal = PREVCANAL;
        else if(bottomDistance <= 10)
            mSignal = MENOSVOLUME;
        else if(bottomDistance > 18)
            mSignal = MAISVOLUME;
        else 
            mSignal = 0;
        
    }

}