#include "Funcionario.h"
class Assalariado : public Funcionario{
	double salario;
	public: 
	Assalariado(){}
	Assalariado(std::string nome_, int matricula_, double s) : Funcionario(nome_, matricula_), salario(s){}
	void setSalario(double n);
	double getSalario();
	double calculaSalario();
	friend std::ostream& operator<< (std::ostream& os,Assalariado& assalariado){
		os << "Nome: " << assalariado.nome <<
		 "\nMatricula: " << assalariado.matricula <<
		 "\nSalario: "  << assalariado.salario << std::endl;
	}
};