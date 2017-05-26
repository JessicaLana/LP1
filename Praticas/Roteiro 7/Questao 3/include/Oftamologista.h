#include "Medico.h"
class Oftamologista : public Medico{
	std::string nomeDoCurso;
	public:
	Oftamologista() : nomeDoCurso(std::string("Oftamologia")){}
	Oftamologista(std::string nome_, double altura_, double peso_) : nomeDoCurso(std::string("Oftamologia")) {	
		nome = std::string(nome_);
		altura = altura_;
		peso = peso_;
	}
	void realizarAtendimento(Paciente& c);
	std::string getNomeCurso();
};