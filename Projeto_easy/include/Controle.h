#ifndef CONTROLE_
#define CONTROLE_
#include "./Detector.h"
#include <stdexcept>
#include <mutex>
#include <thread>
/*! This class uses the state of a Detector to determine which signal shall be sent to the specified server. The processing loop runs concurrently with the connection loop*/
class Controle{
    Detector d; /*!< Detector to be used */
    std::string ipAddrs;/*!< Server addres */
    std::thread detectorThread;/*!< Frame processing thread */
    std::mutex mutex;/*!< Mutex for syncrhonization */
    cv::Point center;/*!< Detected face's center */
    uint8_t signal;/*!< Signal to be sent over network */
    int videoCaptureN = 0; /*!< Capture device to be used (defaults to installed webcam) */
    public:
    Controle(){}/*!< Default constructor */
    Controle(std::string ipAddrs_, int n){} /*!< Constructor, simply initializes and ip address for server and the number of the capture device to be used */
    ~Controle();/*!< Default destructor */
    void load(std::string path); /*!< Loads a different classifier (LBP or Haar-like) */
    void connect(){} /*!< Connect to server with ip ipAddrs*/
    void getSignal(); /*!< Determines which signal shall be sent to server and returns it*/
    void captureLoop(); /*!< Main capture loop, processes each frame with Detector::detect and updates center*/
    void run();/*!< Spawns thread with captureLoop as task and passes its ownership to detectorThread */
    bool running();/*!< Returns 1 if detectorThread is currently running; returns 0 otherwhise */
    cv::Point getCenter(); /*!< Returns the detected face's center as a cv::Point */
};
#endif