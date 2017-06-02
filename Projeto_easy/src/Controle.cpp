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
            //Locks mutex during frame processing - which should take about 30ms.
            mutex.lock();
            capture >> frame;
            if( frame.empty() )
                throw std::runtime_error("Frame vazio, falha ao capturar frame com dispositivo de captura selecionado");
            cv::Mat frame1 = frame.clone();
            //Updating center state
            d.detect(frame1, scale);
            center = d.getCenter();
            //Press q || Q || ESC to exit.
            char c = (char)cv::waitKey(10);
            mutex.unlock();
            if( c == 27 || c == 'q' || c == 'Q' ){
                std::exit(0);
            }
        } 
    }
}

void Controle::run(){
    //Mutex unlocking is only done once thread is spawned and videoCapture device is set up and ready to go lest other threads reference Controle's state while it's still initializing
    mutex.lock();
    detectorThread = std::move(std::thread([=]{captureLoop();}));
}

Controle::~Controle(){
    //On destruction , joins detectorThread if it hasn't exited yet.
    if(detectorThread.joinable())
        detectorThread.join();
}
cv::Point Controle::getCenter(){
    //This function is garanteed to wait for current frame processing loop to be done before returning detected face's center.
    std::lock_guard<std::mutex> guard{mutex};
    return center;
}
bool Controle::running(){
    //Returns 1 if detectorThread hasn't exited yet.
    return detectorThread.joinable();
}