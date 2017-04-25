#ifndef FUNCIONARIO
#define FUNCIONARIO
#include <string>
#include <iostream>
class Funcionario{
	protected: 
	std::string nome;
	int matricula;
	public: 
	Funcionario(){}
	Funcionario(std::string nome_, int matricula_);
	virtual double calculaSalario() = 0;
};
#endif