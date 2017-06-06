#include "../include/Controle.h"
#include <string>
void Controle::getSignal(int n){
    if (n == 1){
        if(center.x <= w/3) mSignal = 'p';
        else if(center.x >= w*2/3) mSignal = 'n';
        else mSignal = 0;
    }
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
            getSignal(1);
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
    detectorThread = std::move(std::thread([=]{captureLoopDlib();}));
    std::cout << "Detector thread spawned and running";
    /*socketThread = std::move(std::thread([=]{
        connect();
        while(1){
            if(mSignal != 0)
                mSocket.sendData((char*)&mSignal, sizeof(uint8_t));
        }
    }));*/
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

void Controle::captureLoopDlib(){
    cv::VideoCapture capture(0);
    cv::Mat frame, image;
    double scale = 1;
    w = capture.get(CV_CAP_PROP_FRAME_WIDTH);
    h = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
    std::cout << "(Width, HEIGHT) = (" << w << "," << h << ")" << std::endl;

    dlib::frontal_face_detector detector = dlib::get_frontal_face_detector();
    dlib::shape_predictor pose_model;
    dlib::deserialize("../shape_predictor_68_face_landmarks.dat") >> pose_model;

    mutex.unlock();
    if(!capture.isOpened())
        std::cout << "Erro abrindo dispositivo de captura" << std::endl;
    else{
        int flag = 0;
        while(1){
            //Locks mutex during frame processing - which should take about 30ms.
            mutex.lock();
            capture >> frame;
            if( frame.empty() )
                throw std::runtime_error("Frame vazio, falha ao capturar frame com dispositivo de captura selecionado");
            

            dlib::cv_image<dlib::bgr_pixel> cimg(frame);
            std::vector<dlib::rectangle> faces = detector(cimg);
            std::vector<dlib::full_object_detection> shapes;
            for(auto e : faces)
                shapes.push_back(pose_model(cimg, e));
            
            if(!shapes.empty()){
                for(int i = 0; i<68 ; i++){
                    cv::Point p(shapes[0].part(i).x(), shapes[0].part(i).y());
                    cv::circle( frame, p, 3, cv::Scalar(255,0,0), 2, 6, 0 );   
                    cv::putText(frame,std::to_string(i),p+cv::Point(-5,-5), cv::FONT_HERSHEY_SIMPLEX, 0.35, cv::Scalar(255,0,0));   
                  
                }
                auto rect = shapes[0].get_rect();
                auto originPoints = dlib::center(rect);
                double ratio = 150.0/rect.width();
                cv::Point newOrigin(originPoints.x(), originPoints.y());

                cv::Point faceCenter(ratio*(shapes[0].part(30).x() - newOrigin.x), ratio*(shapes[0].part(30).y() - newOrigin.y) );
                cv::Point faceRight(ratio*(shapes[0].part(2).x() - newOrigin.x), ratio*(shapes[0].part(2).y() - newOrigin.y ) );
                cv::Point distance = faceCenter - faceRight;
                double rightDistance = std::sqrt(distance.x*distance.x + distance.y*distance.y);
                
                if(rightDistance <= 55 && flag == 0){
                    mSignal = NEXTCANAL;
                    std::cout << "next canal" << std::endl;
                    flag = 1;
                }
                else if(rightDistance >= 110 && flag == 0){
                    mSignal = PREVCANAL;
                    std::cout << "prev canal" << std::endl;
                    flag = 1;
                }
                else {
                    flag = 0;
                    mSignal = 0;
                }
            }

            cv::imshow("result", frame);
            //getSignal(2);
            //Press q || Q || ESC to exit.
            char c = (char)cv::waitKey(10);
            mutex.unlock();
            if( c == 27 || c == 'q' || c == 'Q' ){
                std::exit(0);
            }
        } 
    }
}
