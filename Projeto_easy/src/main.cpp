#include "../include/Detector.h"
#include "../include/Controle.h"
int main(){
    Controle d; 
    d.run();
    while(d.running()){
        std::cout << d.getCenter().x << std::endl;
    }
}