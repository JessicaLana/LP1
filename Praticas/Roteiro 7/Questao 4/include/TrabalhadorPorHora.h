#include "Trabalhador.h"
class TrabalhadorPorHora : public Trabalhador{
	public:
	TrabalhadorPorHora(){}
	TrabalhadorPorHora(std::string nome_, double salario_) : Trabalhador(nome_,salario_){}
	double calcularPagamento(int horas);
};