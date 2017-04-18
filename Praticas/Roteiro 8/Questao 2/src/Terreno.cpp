#include "../include/Terreno.h"
void Terreno::setArea(double n){
	area = n;
}
double Terreno::getArea(){
	return area;
}
void Terreno::getDescricao(){
	std::cout << "Endereço:\n " <<
	"\tLogradouro: " << endereco.getLogradouro() <<
	std::endl << "\tBairro: " << endereco.getBairro() <<
	std::endl << "\tCidade: " << endereco.getCidade() <<
	std::endl << "\tCep: " << endereco.getCep() <<
	std::endl << "Area: " << getArea() << std::endl;
}