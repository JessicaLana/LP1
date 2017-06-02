#include "../include/Controle.h"
void Controle::getSignal(){
    
}
void Controle::captureLoop(){
    cv::VideoCapture capture(0);
    cv::Mat frame, image;
    double scale = 1;
    mutex.unlock();
    if(!capture.isOpened())
        std::cout << "Erro abrindo dispositivo de captura" << std::endl;
    else{
        while(1){
            mutex.lock();
            capture >> frame;
            if( frame.empty() )
                throw std::runtime_error("Frame vazio, falha ao capturar frame com dispositivo de captura selecionado");
            cv::Mat frame1 = frame.clone();
            d.detect(frame1, scale);
            center = d.getCenter();
            char c = (char)cv::waitKey(10);
            mutex.unlock();
            if( c == 27 || c == 'q' || c == 'Q' ){
                std::exit(0);
            }
        } 
    }
}

void Controle::run(){
    mutex.lock();
    detectorThread = std::move(std::thread([=]{captureLoop();}));
}

Controle::~Controle(){
    if(detectorThread.joinable())
        detectorThread.join();
}
cv::Point Controle::getCenter(){
    std::lock_guard<std::mutex> guard{mutex};
    return center;
}
bool Controle::running(){
    return detectorThread.joinable();
}