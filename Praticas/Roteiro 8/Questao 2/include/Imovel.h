#ifndef IMOVEL
#define IMOVEL
#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include "Endereco.h"
class Imovel{
	protected:
	Endereco endereco;
	public:
	Imovel(){}
	Imovel(Endereco e) : endereco(e){}
	Endereco getEndereco();
	virtual std::string getDescricao() = 0;
};
#endif