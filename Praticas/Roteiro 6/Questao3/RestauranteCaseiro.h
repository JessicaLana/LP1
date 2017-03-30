#ifndef RESTCASEIRO
#define RESTCASEIRO
#include "MesaDeRestaurante.h"
class RestauranteCaseiro{
	std::vector<MesaDeRestaurante> mesas;
	public:
	RestauranteCaseiro(){}
	RestauranteCaseiro(std::vector<MesaDeRestaurante> _mesas) : mesas(_mesas){}
	void adicionaAoPedido(Pedido p, int n);
	double calculaTotalRestaurante();
};
#endif