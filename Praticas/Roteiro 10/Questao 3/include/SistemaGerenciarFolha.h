#ifndef GERENCIARFOLHA
#define GERENCIARFOLHA
#include "./Funcionario.h"
#include <string>
#include <algorithm>
#include <vector>
class SistemaGerenciarFolha{
	std::vector<Funcionario*> funcionarios;
	public: 
	SistemaGerenciarFolha(){}
	SistemaGerenciarFolha(std::vector<Funcionario*>& func) : funcionarios(func){}
	void setFuncionarios(std::vector<Funcionario*>& funcionarios);
	double calcularValorTotalFolha();
	double consultaSalarioFuncionario(int matricula_);
};
#endif