#include "../include/Circulo.h"
double Circulo::calcularArea(){
	return PI * std::pow(raio, 2);
}
double Circulo::getRaio(){
	return raio;
}
void Circulo::setRaio(double n){
	raio = n;
}