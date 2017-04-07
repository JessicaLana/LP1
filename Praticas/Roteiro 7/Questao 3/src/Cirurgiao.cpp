#include "../include/Cirurgiao.h"
void Cirurgiao::realizarAtendimento(Paciente& c){
	std::string descricaoAtendimento; 
	//descricaoAtendimento = gerarDescricao(); nao implementado
	Prontuario novoProntuario(Prontuario::gerarProntuario(descricaoAtendimento));
	c.atualizarProntuario(novoProntuario);
}

std::string Cirurgiao::getNomeCurso(){
	return nomeDoCurso;
}