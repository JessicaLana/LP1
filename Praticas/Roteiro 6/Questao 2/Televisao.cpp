#include "Televisao.h"
unsigned int Televisao::getVolume(){
	return volume;
}
int Televisao::getCanal(){
	return canal;
}
void Televisao::proxCanal(){
	canal++;
}
void Televisao::antCanal(){
	if(canal >0 )
		canal--;
}
void Televisao::maisVolume(){
	volume++;
}
void Televisao::menosVolume(){
	if(volume > 0)
		volume--;
}
void Televisao::setVolume(unsigned int n){
	volume = n;
}
void Televisao::setCanal(int n){
	canal = n;
}
Televisao::Televisao(int canal_, int volume_){
	canal = canal_;
	volume = volume_;
}