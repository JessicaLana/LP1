#include "../include/Detector.h"
Detector::Detector(std::string path) : filePath(path){
    if(!classifier.load(path))
        std::cout << "Erro, não pode abrir o caminho do classificador" << std::endl;
    else   
        std::cout << "Detector carregado" << std::endl;
}
Detector::Detector(){
    if(!classifier.load(filePath))
        std::cout << "Erro, não pode abrir o caminho do classificador" << std::endl;
    else   
        std::cout << "Detector carregado" << std::endl;
}
cv::Point Detector::getCenter(){
    return center;
}
void Detector::detect(cv::Mat& img, double scale){
    double t = 0;
    assert(!img.empty());
    std::vector<cv::Rect> faces, faces2;
    cv::Mat gray, smallImg;
    cv::cvtColor( img, gray, cv::COLOR_BGR2GRAY );
    double fx = 1 / scale;
    cv::resize( gray, smallImg, cv::Size(), fx, fx, cv::INTER_LINEAR );
    cv::equalizeHist( smallImg, smallImg );
    t = (double)cv::getTickCount();
    classifier.detectMultiScale( smallImg, faces,
        1.1, 2, 0
        //|CASCADE_FIND_BIGGEST_OBJECT
        //|CASCADE_DO_ROUGH_SEARCH
        |2,
        cv::Size(30, 30) );

    t = (double)cv::getTickCount() - t;
   // printf( "detection time = %g ms\n", t*1000/cv::getTickFrequency());
    if(faces.size() == 0) imshow("result", img);
    for ( size_t i = 0; i < faces.size(); i++ ){
        cv::Rect r = faces[i];
        cv::Mat smallImgROI;
        std::vector<cv::Rect> nestedObjects;
        int radius;

        double aspect_ratio = (double)r.width/r.height;
        if( 0.75 < aspect_ratio && aspect_ratio < 1.3 ){
            center.x = cvRound((r.x + r.width*0.5)*scale);
            center.y = cvRound((r.y + r.height*0.5)*scale);
            radius = cvRound((r.width + r.height)*0.25*scale);
            cv::circle( img, center, radius, cv::Scalar(255,0,0), 3, 8, 0 );      
        }
        else{
            center = cvPoint(cvRound((r.x + r.width-1)*scale), cvRound((r.y + r.height-1)*scale));
        }
      //  std::cout << center.x << " " << center.y << std::endl;
        imshow("result", img);
    }
}