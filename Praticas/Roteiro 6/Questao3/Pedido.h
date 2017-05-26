#ifndef PEDIDO
#define PEDIDO
#include <string>
class Pedido{
	int numero;
	std::string descricao;
	int quantidade;
	double preco;
	public:
	Pedido(){}
	Pedido(int n, std::string d, int q, double p);
	void setDescricao(std::string s);
	void setNumero(int n);
	void setQuantidade(int n);
	void setPreco(double p);

	std::string getDescricao();
	int getNumero();
	int getQuantidade();
	double getPreco();
};
#endif