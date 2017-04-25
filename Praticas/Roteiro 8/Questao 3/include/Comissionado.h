#ifndef COMISSIONADO
#define COMISSIONADO
#include "Funcionario.h"
class Comissionado : public Funcionario{
	double vendasSemanais;
	double percentualComissao;
	double salarioBase;
	public: 
	Comissionado(){}
	Comissionado(std::string nome_, int matricula_, double vS, double pC, double sB) : salarioBase(sB),Funcionario(nome_, matricula_), vendasSemanais(vS), percentualComissao(pC){}
	double calculaSalario();
	double getVendas();
	double getPercentual();
	void setVendas(double n);                        
	void setPercentual(double n);
	friend std::ostream& operator<< (std::ostream& os,Comissionado& comissionado){
		os << "Nome: " << comissionado.nome <<
		 "\nMatricula: " << comissionado.matricula <<
		 "\nSalario base: "  << comissionado.salarioBase << 
		 "\nVendas por semana: " << comissionado.vendasSemanais <<
		 "\nPercentual da comissao: " << comissionado.percentualComissao << "%" << std::endl;
	}
};
#endif