#include "../include/TrabalhadorAssalariado.h"
double TrabalhadorAssalariado::calcularPagamento(int horas){
	if(horas < 0)
		throw std::runtime_error("Bad horas");
	else 
		return std::floor(horas/40.0)*salario;
}