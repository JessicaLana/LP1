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
    SocketCliente mSocket;/*!< Communication channell - a simple TCP Socket */
    std::thread socketThread; /*!< This thread handles communication */
    Detector d; /*!< Detector to be used */
    std::string ipAddrs;/*!< Server addres */
    std::thread detectorThread;/*!< Frame processing thread */
    std::mutex mutex;/*!< Mutex for syncrhonization */
    cv::Point center;/*!< Detected face's center */
    int videoCaptureN = 0; /*!< Capture device to be used (defaults to installed webcam) */
    unsigned char mSignal;/*!< Signal to be sent over network */
    double w, h; /*!< Camera resolution */
    
    public:
    Controle(){}/*!< Default constructor, data file is expected to be in this project's root directory */
    Controle(std::string ipAddrs_,unsigned long port, int n) : mSocket(ipAddrs_, port), videoCaptureN(n), ipAddrs(ipAddrs_){} /*!< Constructor, simply initializes and ip address for server and the number of the capture device to be used */
    ~Controle();/*!< Default destructor */
    void connect(); /*!< Connect to server with ip ipAddrs*/
    uint8_t getSignal(); /*!< Determines which signal shall be sent to server and returns it, then updates mSignal*/
    void captureLoop(); /*!< Main capture loop, processes each frame with Detector::detect and updates center and mSignal*/
    void run();/*!< Spawns detectorThread and socketThread with respective loops */
    bool running();/*!< Returns 1 if both detectorThread  and SocketThread are currently running; returns 0 otherwhise */
};
#endif