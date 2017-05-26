#include "../include/Otorrino.h"
void Otorrino::realizarAtendimento(Paciente& c){
	std::string descricaoAtendimento; 
	//descricaoAtendimento = gerarDescricao(); nao implementado
	Prontuario novoProntuario(Prontuario::gerarProntuario(descricaoAtendimento));
	c.atualizarProntuario(novoProntuario);
}

std::string Otorrino::getNomeCurso(){
	return nomeDoCurso;
}