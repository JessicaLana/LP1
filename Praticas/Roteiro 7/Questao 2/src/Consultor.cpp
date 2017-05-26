#include "../include/Consultor.h"

double Consultor::getSalario(){
	salario *= 1.1;
	return salario;
}
double Consultor::getSalario(float perc){
	salario *= 1+perc/100.0;
	return salario;
}