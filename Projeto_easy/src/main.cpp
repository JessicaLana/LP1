#include "../include/Detector.h"
#include "../include/Controle.h"
#include <chrono>
int main(){
    Controle d(std::string("127.0.0.1"), 85, 0); 
    try{
        d.run();
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
}
