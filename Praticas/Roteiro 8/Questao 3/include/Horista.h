#ifndef HORISTA
#define HORISTA
#include "Funcionario.h"
#include <iostream>
class Horista : public Funcionario{
	double salarioPorHora;
	double horasTrabalhadas;
	public: 
	Horista(){}
	Horista(std::string nome_, int matricula_, double sH, double hT) : Funcionario(nome_, matricula_), salarioPorHora(sH), horasTrabalhadas(hT) {}
	double calculaSalario();
	double getSalarioPorHora();
	double getHorasTrabalhadas();
	void setSalarioPorHora(double n);
	void setHorasTrabalhadas(double n);
	friend std::ostream& operator<< (std::ostream& os,Horista& horista){
		os << "Nome: " << horista.nome <<
		 "\nMatricula: " << horista.matricula <<
		 "\nSalario por hora: "  << horista.salarioPorHora << 
		 "\nHoras trabalhadas: " << horista.horasTrabalhadas << std::endl;
	}
};
#endif