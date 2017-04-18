#ifndef ENDERECO
#define ENDERECO
#include <string>
class Endereco{
	std::string logradouro, bairro, cidade, cep;
	int numero;
	public:
	Endereco(){}
	Endereco(std::string l, std::string b, std::string ci, std::string ce, int n);
	std::string getLogradouro();
	std::string getBairro();
	std::string getCidade();
	std::string getCep();
};
#endif