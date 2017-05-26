#include "Trabalhador.h"
class TrabalhadorAssalariado : public Trabalhador{
	public:
	TrabalhadorAssalariado(){}
	TrabalhadorAssalariado(std::string nome_, double salario_) : Trabalhador(nome_, salario_){}
	double calcularPagamento(int horas);
};