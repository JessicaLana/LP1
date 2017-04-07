#include "Medico.h"
class Cirurgiao : public Medico{
	std::string nomeDoCurso;
	public:
	Cirurgiao() : nomeDoCurso(std::string("Cirurgiao")){}
	Cirurgiao(std::string nome_, double altura_, double peso_) : nomeDoCurso(std::string("Cirurgiao")) {	
		nome = std::string(nome_);
		altura = altura_;
		peso = peso_;
	}
	void realizarAtendimento(Paciente& c);
	std::string getNomeCurso();
};