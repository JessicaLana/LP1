#ifndef CONTROLE_
#define CONTROLE_
#include "./Detector.h"
#include <stdexcept>
#include <mutex>
#include <thread>
class Controle{
    Detector d;
    std::string ipAddrs;
    std::thread detectorThread;
    std::mutex mutex;
    cv::Point center;
    uint8_t signal;
    int videoCaptureN = 0;
    public:
    Controle(){}
    Controle(std::string ipAddrs_, int n){}
    ~Controle();
    void load(std::string path);
    void connect(){}
    void getSignal();
    void captureLoop();
    void run();
    bool running();
    cv::Point getCenter();
};
#endif