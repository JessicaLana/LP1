#include "../include/Controle.h"
void Controle::getSignal(){
    if(center.x <= w/3) mSignal = 'p';
    else if(center.x >= w*2/3) mSignal = 'n';
    else mSignal = 0;
}
void Controle::captureLoop(){
    cv::VideoCapture capture(0);
    cv::Mat frame, image;
    double scale = 1;
    w = capture.get(CV_CAP_PROP_FRAME_WIDTH);
    h = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
    std::cout << "(Width, HEIGHT) = (" << w << "," << h << ")" << std::endl;
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
            getSignal();
            //Press q || Q || ESC to exit.
            char c = (char)cv::waitKey(10);
            mutex.unlock();
            if( c == 27 || c == 'q' || c == 'Q' ){
                std::exit(0);
            }
        } 
    }
}
void Controle::connect(){
    mSocket.connectToServer();
}
void Controle::run(){
    //Mutex unlocking is only done once thread is spawned and videoCapture device is set up and ready to go lest other threads reference Controle's state while it's still initializing
    mutex.lock();
    detectorThread = std::move(std::thread([=]{captureLoop();}));
    std::cout << "Detector thread spawned and running";
    socketThread = std::move(std::thread([=]{
        connect();
        while(1){
            if(mSignal != 0)
                mSocket.sendData((char*)&mSignal, sizeof(uint8_t));
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
cv::Point Controle::getCenter(){
    //This function is garanteed to wait for current frame processing loop to be done before returning detected face's center.
    std::lock_guard<std::mutex> guard{mutex};
    return center;
}
bool Controle::running(){
    //Returns 1 if detectorThread hasn't exited yet.
    return detectorThread.joinable();
}