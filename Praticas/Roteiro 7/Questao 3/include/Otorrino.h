#include "Medico.h"
class Otorrino : public Medico{
	std::string nomeDoCurso;
	public:
	Otorrino() : nomeDoCurso(std::string("Ortorrinolaringologia")){}
	Otorrino(std::string nome_, double altura_, double peso_) : nomeDoCurso(std::string("Ortorrinolaringologia")) {	
		nome = std::string(nome_);
		altura = altura_;
		peso = peso_;
	}
	void realizarAtendimento(Paciente& c);
	std::string getNomeCurso();
};