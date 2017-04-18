#include "../include/Apartamento.h"
double Apartamento::getValor(){
	return valorDoCondominio;
}
std::string Apartamento::getPos(){
	return posicao;
}
int Apartamento::getNumeroVagas(){
	return numeroDeVagasNaGaragem;
}
void Apartamento::setPos(std::string p){
	posicao = p;
}
void Apartamento::setValor(double n){
	valorDoCondominio = n;
}
void Apartamento::setNumeroVagas(int n){
	numeroDeVagasNaGaragem = n;
}
Apartamento::Apartamento(std::string pos, double valor, int numero, Endereco e) : Imovel(e){
	posicao = pos;
	setValor(valor);
	setNumeroVagas(numero);
}
void Apartamento::getDescricao(){
	std::cout << "Endereço:\n " <<
	"\tLogradouro: " << endereco.getLogradouro() <<
	std::endl << "\tBairro: " << endereco.getBairro() <<
	std::endl << "\tCidade: " << endereco.getCidade() <<
	std::endl << "\tCep: " << endereco.getCep() <<
	std::endl << "Posicao: " << getPos() << 
	std::endl << "Valor do condomineo: " << getValor() <<
	std::endl << "Numero de vagas na garagem: " << getNumeroVagas() << std::endl;
}