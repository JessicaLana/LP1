#include "../include/Detector.h"
#include "../include/Controle.h"
#include <chrono>
int main(){
    Controle d(std::string("192.168.0.18"), 81, 0); 
    try{
        d.run();
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
   /* while(d.running()){
        std::cout << d.getCenter().x << std::endl;
        std::this_thread::sleep_for(std::chrono::duration<int, std::ratio<1> >(1));
    }*/
}