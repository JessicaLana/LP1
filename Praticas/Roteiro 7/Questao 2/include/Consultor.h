#include "Funcionario.h"

class Consultor : public Funcionario{
	public:
	double getSalario();
	double getSalario(float perc);
	Consultor(){}
	Consultor(std::string matricula_, std::string nome_, double salario_ ){
		setMatricula(matricula_);
		setNome(nome_);
		setSalario(salario_);
	}
};