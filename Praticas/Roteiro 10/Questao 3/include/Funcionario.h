#ifndef FUNCIONARIO
#define FUNCIONARIO
#include <string>
#include <exception>
#include <iostream>
class FuncionarioNaoExisteException : std::exception{
	public: 
	const char* what(){
		return "Funcionario nao existe";
	}
};
class OrcamentoEstouradoException : std::exception {
	public: 
	const char* what() {
		return "Orçamento estourado";
	}
};
class Funcionario{
	protected: 
	std::string nome;
	int matricula;
	public: 
	Funcionario(){}
	Funcionario(std::string nome_, int matricula_);
	virtual double calculaSalario() = 0;
	int getMatricula();
	std::string getNome();
	void setMatricula(int n);
	void setNome(std::string nome);

};
#endif