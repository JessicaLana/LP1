#include "../include/Funcionario.h"
Funcionario::Funcionario(std::string nome_, int matricula_){
	nome = nome_;
	matricula = matricula_;
}
int Funcionario::getMatricula(){
	return matricula;
}
std::string Funcionario::getNome(){
	return nome;
}
void Funcionario::setMatricula(int n){
	matricula = n;
}
void Funcionario::setNome(std::string nome_){
	nome = nome_;
}