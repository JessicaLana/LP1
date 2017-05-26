#include "../include/Ginecologista.h"
void Ginecologista::realizarAtendimento(Paciente& c){
	std::string descricaoAtendimento; 
	//descricaoAtendimento = gerarDescricao(); nao implementado
	Prontuario novoProntuario(Prontuario::gerarProntuario(descricaoAtendimento));
	c.atualizarProntuario(novoProntuario);
}

std::string Ginecologista::getNomeCurso(){
	return nomeDoCurso;
}