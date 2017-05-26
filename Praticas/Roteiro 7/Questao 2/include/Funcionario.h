#ifndef FUNCIONARIO
#define FUNCIONARIO
#include <string>
class Funcionario{
	protected:
	std::string matricula;
	std::string nome;
	double salario;
	public:
	Funcionario(){}
	Funcionario(std::string ma, std::string n, double s) : matricula(ma), nome(n), salario(s){}
	void setMatricula(std::string ma);
	void setNome(std::string n);
	void setSalario(double n);
	std::string getMatricula();
	std::string getNome();
	virtual double getSalario();
};
#endif
