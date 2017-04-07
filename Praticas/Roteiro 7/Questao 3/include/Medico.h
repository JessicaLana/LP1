#ifndef MEDICO 
#define MEDICO
#include <string>
#include "./Paciente.h"
class Medico{
	protected:
	std::string nome;
	double altura;
	double peso;
	public:
	Medico(){}
	std::string getNome();
	double getAltura();
	double getPeso();
	void setNome(std::string nome_);
	void setAltura(double altura_);
	void setPeso(double peso_);
	virtual std::string getNomeCurso(){};
	virtual void realizarAtendimento(Paciente& c){}; 
};
#endif