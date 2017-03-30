#include "RestauranteCaseiro.h"
void RestauranteCaseiro::adicionaAoPedido(Pedido p, int n){
	mesas[n].adicionaAoPedido(p);
}
double RestauranteCaseiro::calculaTotalRestaurante(){
	double sum = 0;
	for(auto e : mesas) sum += e.calculaTotal();
}