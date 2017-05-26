#include "../include/Trabalhador.h"
#include <stdexcept>
void Trabalhador::setSalario(double s){
	if(s >= 0)
		salario = s;
	else 
		throw std::runtime_error("Bad salario");
}
void Trabalhador::setNome(std::string n){
	nome = n;
}
double Trabalhador::getSalario(){
	return salario;
}
std::string Trabalhador::getNome(){
	return nome;
}
