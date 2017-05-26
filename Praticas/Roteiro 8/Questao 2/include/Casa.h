#include "Imovel.h"
#include "Endereco.h"
#include <iostream>

class Casa : public Imovel{
	int numeroDePavimentos;
	int quantidadeDeQuartos;
	double areaDoTerreno;
	double areaConstruida;
	public:
	Casa(){}
	Casa(Endereco e, int nP, int nQ, double aT, double aC);
	void setNumeroPavimentos(int n);
	void setQuantidadeQuartos(int n);
	void setAreaTerreno(double n);
	void setAreaConstruida(double n);
	int getNumeroPavimentos();
	int getQuantidadeQuartos();
	double getAreaTerreno();
	double getAreaConstruida();
	std::string getDescricao();
};