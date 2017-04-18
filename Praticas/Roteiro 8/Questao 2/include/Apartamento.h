#include "Imovel.h"
class Apartamento : public Imovel{
	std::string posicao;
	double valorDoCondominio;
	int numeroDeVagasNaGaragem;
	public:
	Apartamento(){}
	Apartamento(std::string pos, double valor, int numero, Endereco e);
	double getValor();
	std::string getPos();
	int getNumeroVagas();
	void setPos(std::string p);
	void setValor(double n);
	void setNumeroVagas(int n);
	void getDescricao();
};