#ifndef IMOVEL
#define IMOVEL
#include <string>
#include <iostream>
#include "Endereco.h"
class Imovel{
	protected:
	Endereco endereco;
	public:
	Imovel(){}
	Imovel(Endereco e) : endereco(e){}
	Endereco getEndereco();
	virtual void getDescricao() = 0;
};
#endif