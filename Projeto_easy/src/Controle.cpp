#include "../include/Controle.h"
#include <string>
#include <chrono>
#include <numeric>
uint8_t Controle::getSignal(){
    std::lock_guard<std::mutex> guard(mutex);
    return mSignal;
}
void Controle::connect(){
    mSocket.connectToServer();
}
void Controle::run(){
    //Mutex unlocking is only done once thread is spawned and videoCapture device is set up and ready to go lest other threads reference Controle's state while it's still initializing
    mutex.lock();
    //Launching capture loop thread
    detectorThread = std::move(std::thread([=]{captureLoop();}));
    std::cout << "Detector thread spawned and running";
    //Launching socket thread
    socketThread = std::move(std::thread([=]{
        connect();
        while(1){
                mSocket.sendData(std::to_string(mSignal).c_str(), 1);
                std::this_thread::sleep_for(std::chrono::duration<int, std::ratio<1, 2> >(1));
        }
    }));
    std::cout << "Socket thread spawned and running" << std::endl;
}

Controle::~Controle(){
    //On destruction , joins running threads if they haven't exited yet.
    if(detectorThread.joinable())
        detectorThread.join();
    if(socketThread.joinable())
        socketThread.join();
}
bool Controle::running(){
    //Returns 1 if detectorThread and socketThread haven't exited yet.
    return (detectorThread.joinable() && socketThread.joinable() );
}
void Controle::captureLoop(){
    cv::VideoCapture capture(0);
    cv::Mat frame, image;
    double scale = 1;
    w = capture.get(CV_CAP_PROP_FRAME_WIDTH);
    h = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
    //Print camera resolution on startup
    std::cout << "(Width, HEIGHT) = (" << w << "," << h << ")" << std::endl;
    //Unlock mutex, now other threads can access Controle's state
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
            //Call detector and update signal accordingly
            d.detect(frame);
            mSignal = d.getSignal();
            cv::imshow("result", frame);
            //Press q || Q || ESC to exit.
            char c = (char)cv::waitKey(10);
            mutex.unlock();
            if( c == 27 || c == 'q' || c == 'Q' ){
                std::exit(0);
            }
        } 
    }
}

