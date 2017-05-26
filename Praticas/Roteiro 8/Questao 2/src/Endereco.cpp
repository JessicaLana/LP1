#include "../include/Endereco.h"
std::string Endereco::getLogradouro(){
	return logradouro;
}
std::string Endereco::getBairro(){
	return bairro;
}
std::string Endereco::getCidade(){
	return cidade;
}
std::string Endereco::getCep(){
	return cep;
}
Endereco::Endereco(std::string l, std::string b, std::string ci, std::string ce, int n){
	logradouro = l;
	bairro = b;
	cidade = ci;
	cep = ce;
	numero = n;
}