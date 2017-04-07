#include "../include/Paciente.h"
void Paciente::atualizarProntuario(std::string atendimento){
	Prontuario::gerarProntuario(atendimento);
	std::string novaInfo = "foo";
	
	prontuario.atualizarInfo(novaInfo);
	std::cout << "Prontuario do paciente " << nome << " atualizado e pronto para emissao" << std::endl;
}
void Paciente::atualizarProntuario(Prontuario p){
	prontuario.atualizarInfo(p);
	std::cout << "Prontuario do paciente " << nome << " atualizado e pronto para emissao" << std::endl;
}