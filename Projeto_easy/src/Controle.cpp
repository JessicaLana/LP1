#include "../include/Controle.h"
void Controle::getSignal(){
    
}
void Controle::captureLoop(){
    cv::VideoCapture capture(0);
    cv::Mat frame, image;
    double scale = 1;
    if(!capture.isOpened())
        std::cout << "Erro abrindo dispositivo de captura" << std::endl;
    else{
        while(1){
            capture >> frame;
            if( frame.empty() )
                break;
            cv::Mat frame1 = frame.clone();
            d.detect(frame1, scale);

            char c = (char)cv::waitKey(10);
            if( c == 27 || c == 'q' || c == 'Q' )
                break;
        } 
    }
}