#ifndef MESA
#define MESA
#include <vector>
#include "Pedido.h"
class MesaDeRestaurante{
	std::vector<Pedido> pedidos;
	public:
	MesaDeRestaurante(){}
	MesaDeRestaurante(std::vector<Pedido> p) : pedidos(p){}
	void adicionaAoPedido(Pedido p);
	void zeraPedidos();
	double calculaTotal();
	MesaDeRestaurante& operator=(const MesaDeRestaurante& a) = default; //Construtor de copia padrao
};
#endif