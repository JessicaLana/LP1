#ifndef TRABALHADOR
#define TRABALHADOR
#include <string>
#include <cmath>
#include <stdexcept>
class Trabalhador{
	protected:
	std::string nome;
	double salario;
	public:
	Trabalhador(){}
	Trabalhador(std::string nome_, double salario_) : nome(nome_), salario(salario_){}
	void setSalario(double s);
	void setNome(std::string n);
	double getSalario();
	std::string getNome();
	virtual double calcularPagamento(int horas){};
};
#endif