#include "../include/Detector.h"
#include "../include/Controle.h"
int main(){
    Controle d(std::string("192.168.0.101"), 8000, 0); 
    try{
        d.run();
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
    using namespace std::chrono_literals;
    while(d.running()){
        std::cout << d.getCenter().x << std::endl;
        std::this_thread::sleep_for(1s);
    }
}