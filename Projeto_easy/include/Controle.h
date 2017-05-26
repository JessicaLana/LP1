#ifndef CONTROLE_
#define CONTROLE_
#include "./Detector.h"
class Controle{
    Detector d;
    std::string ipAddrs;
    cv::Point center;
    uint8_t signal;
    int videoCaptureN = 0;
    public:
    Controle(){}
    Controle(std::string ipAddrs_, int n){}
    void load(std::string path);
    void connect(){}
    void getSignal();
    void captureLoop();
};
#endif