#include "../include/Quadrado.h"

void Quadrado::setAresta(double n){
	aresta =n;
}
double Quadrado::getAresta(){
	return aresta;
}
double Quadrado::calcularArea(){
	return aresta*aresta;
}