#include "../include/SistemaGerenciarFolha.h"
void SistemaGerenciarFolha::setFuncionarios(std::vector<Funcionario*>& funcionarios_){
	funcionarios = funcionarios_;
}
double SistemaGerenciarFolha::calcularValorTotalFolha(){
	double sum = 0;
	for(auto e : funcionarios){
		sum += e->calculaSalario();
	}
	return sum;
}
double SistemaGerenciarFolha::consultaSalarioFuncionario(int matricula_){
	int a = -1;
	double salario;
	for(auto e : funcionarios){
		if(e->getMatricula() == matricula_){
			 a = 1;
			  salario = e->calculaSalario();
		}
	}
	if(a<0) {
		std::cerr << "Erro, funcionario nao matriculado" << std::endl;
		return -1;
	}
	return salario;
}