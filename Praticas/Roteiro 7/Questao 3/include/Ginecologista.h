#include "Medico.h"
class Ginecologista : public Medico{
	std::string nomeDoCurso;
	public:
	Ginecologista() : nomeDoCurso(std::string("Ginecologia")){}
	Ginecologista(std::string nome_, double altura_, double peso_) : nomeDoCurso(std::string("Ginecologia")) {	
		nome = std::string(nome_);
		altura = altura_;
		peso = peso_;
	}
	void realizarAtendimento(Paciente& c);
	std::string getNomeCurso();
};