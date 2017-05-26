#include "../include/Oftamologista.h"
void Oftamologista::realizarAtendimento(Paciente& c){
	std::string descricaoAtendimento; 
	//descricaoAtendimento = gerarDescricao(); nao implementado
	Prontuario novoProntuario(Prontuario::gerarProntuario(descricaoAtendimento));
	c.atualizarProntuario(novoProntuario);
}

std::string Oftamologista::getNomeCurso(){
	return nomeDoCurso;
}