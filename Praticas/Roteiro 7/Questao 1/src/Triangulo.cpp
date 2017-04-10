#include "../include/Triangulo.h"
double Triangulo::calcularArea(){
	return base*altura/2;
}
void Triangulo::setAltura(double n){
	altura = n;
}
void Triangulo::setBase(double n){
	base = n;
}
double Triangulo::getAltura(){
	return altura;
}
double Triangulo::getBase(){
	return base;
}