#include "../include/Casa.h"
void Casa::setNumeroPavimentos(int n){
	if(n > 0)
		numeroDePavimentos = n;
	else
	 	std::cerr<<"Numero negativo de pavimentos" << std::endl;
}
void Casa::setQuantidadeQuartos(int n){
	if(n>0)
		quantidadeDeQuartos = n;
	else
		std::cerr << "Quantidade negativa de quartos" << std::endl;
}
void Casa::setAreaTerreno(double n){
	if(n > 0)
		areaDoTerreno = n;
	else 
		std::cerr << "Area negativa" << std::endl;
}
void Casa::setAreaConstruida(double n){
	if(n > 0)
		areaConstruida = n;
	else
		std::cerr << "Area negativa construida" << std::endl;
}
int Casa::getNumeroPavimentos(){
	return numeroDePavimentos;
}
int Casa::getQuantidadeQuartos(){
	return quantidadeDeQuartos;
}
double Casa::getAreaTerreno(){
	return areaDoTerreno;
}
double Casa::getAreaConstruida(){
	return areaConstruida;
}
std::string Casa::getDescricao(){
	std::ostringstream streamDescricao;
	streamDescricao << "Endereço:\n " <<
	"\tLogradouro: " << endereco.getLogradouro() <<
	std::endl << "\tBairro: " << endereco.getBairro() <<
	std::endl << "\tCidade: " << endereco.getCidade() <<
	std::endl << "\tCep: " << endereco.getCep() <<
	std::endl << "Numero de pavimentos: " << numeroDePavimentos << 
	std::endl << "Quantidade de quartos: " << quantidadeDeQuartos <<
	std::endl << "Area do terreno: " << areaDoTerreno <<
	std::endl << "Area construida: " << areaConstruida << std::endl;
	return streamDescricao.str();
}
Casa::Casa(Endereco e, int nP, int nQ, double aT, double aC) : Imovel(e){
	setNumeroPavimentos(nP);
	setQuantidadeQuartos(nQ);
	setAreaTerreno(aT);
	setAreaConstruida(aC);
}