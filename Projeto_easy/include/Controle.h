#ifndef CONTROLE_
#define CONTROLE_
/*! \mainpage My Personal Index Page
 *
 * \section intro_sec Introduction
 *
 * In this project the OpenCV library was used to implement a simple network driven, webcam powered TV controler. Volume and channels are switched according to your face's position in respect to your video capture device; possible commands are left(Channell--), right(Channell++), up(Volume++), down(Volume--). A cpp wrapper on linux C TCP sockets was also implemented for convenience.
 *
 * Projeto da disciplina Linguagem de Programação I, UFPB-2016.1.Vinicius M. Mendes de Moura e  Jessica Lana Ricardo da Silva  Braga.
 * \section install_sec Installation
 *  Assuming you have cloned this project and are currently in its root directory:\n
 *      $ cd build\n
 *      $ cmake ..\n
 *      $ make\n
 *  Done. Now you can run ./main in this directory
 */
#include "./Detector.h"
#include "./Socket.h"
#include <stdexcept>
#include <mutex>
#include <thread>
/*! This class uses the state of a Detector to determine which signal shall be sent to the specified server. The processing loop runs concurrently with the connection loop*/
class Controle{
    Socket mSocket;/*!< Communication channell - a simple TCP Socket */
    std::thread socketThread; /*!< This thread handles communication */
    Detector d; /*!< Detector to be used */
    std::string ipAddrs;/*!< Server addres */
    std::thread detectorThread;/*!< Frame processing thread */
    std::mutex mutex;/*!< Mutex for syncrhonization */
    cv::Point center;/*!< Detected face's center */
    uint8_t mSignal;/*!< Signal to be sent over network */
    int videoCaptureN = 0; /*!< Capture device to be used (defaults to installed webcam) */
    double w, h;
    public:
    Controle(){}/*!< Default constructor */
    Controle(std::string ipAddrs_,unsigned long port, int n) : mSocket(ipAddrs_, port), videoCaptureN(n), ipAddrs(ipAddrs_){} /*!< Constructor, simply initializes and ip address for server and the number of the capture device to be used */
    ~Controle();/*!< Default destructor */
    void load(std::string path); /*!< Loads a different classifier (LBP or Haar-like) */
    void connect(); /*!< Connect to server with ip ipAddrs*/
    void getSignal(); /*!< Determines which signal shall be sent to server and returns it, then updates mSignal*/
    void captureLoop(); /*!< Main capture loop, processes each frame with Detector::detect and updates center and mSignal*/
    void run();/*!< Spawns detectorThread and socketThread with respective loops */
    bool running();/*!< Returns 1 if detectorThread is currently running; returns 0 otherwhise */
    cv::Point getCenter(); /*!< Returns the detected face's center as a cv::Point. This function is garanteed to wait for current frame processing loop to be done before returning detected face's center.*/
};
#endif