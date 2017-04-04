#include "MesaDeRestaurante.h"
void MesaDeRestaurante::adicionaAoPedido(Pedido p){
	pedidos.push_back(p);
}
void MesaDeRestaurante::zeraPedidos(){
	pedidos.clear();
}

double MesaDeRestaurante::calculaTotal(){
	double sum = 0;
	for(auto e : pedidos) sum += e.getPreco()*e.getQuantidade();
	return sum;
}