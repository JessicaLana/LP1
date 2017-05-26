#include "../include/Horista.h"
double Horista::calculaSalario(){
	if(horasTrabalhadas <= 40){
		return salarioPorHora*horasTrabalhadas;
	}
	else 
		return salarioPorHora*40.0 + salarioPorHora*40*1.5;
}
double Horista::getSalarioPorHora(){
	return salarioPorHora;
}
double Horista::getHorasTrabalhadas(){
	return horasTrabalhadas;
}
void Horista::setSalarioPorHora(double n){
	salarioPorHora = n;
}
void Horista::setHorasTrabalhadas(double n){
	horasTrabalhadas = n;
}