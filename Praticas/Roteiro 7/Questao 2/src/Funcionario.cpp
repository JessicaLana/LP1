#include "../include/Funcionario.h"
void Funcionario::setMatricula(std::string ma){
	matricula = ma;
}
void Funcionario::setNome(std::string n){
	nome = n;
}
void Funcionario::setSalario(double n){
	salario = n;
}
std::string Funcionario::getNome(){
	return nome;
}
std::string Funcionario::getMatricula(){
	return matricula;
}
double Funcionario::getSalario(){
	return salario;
}