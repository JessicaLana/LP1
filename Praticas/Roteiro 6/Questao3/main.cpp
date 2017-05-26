#include "RestauranteCaseiro.h"
#include <string>
#include <iostream>
using namespace std;
int main(){
	std::vector<Pedido> pedidos = {Pedido(1,std::string("Carne"), 2, 1),Pedido(3,std::string("Vegetais"), 1, 1)};
	std::vector<Pedido> pedidos2 = {Pedido(2,std::string("Frango"), 1, 1),Pedido(4,std::string("Coco"), 1, 1)};
	MesaDeRestaurante a(pedidos);
	MesaDeRestaurante b(pedidos2);
	std::vector<MesaDeRestaurante> m = {a, b};
	RestauranteCaseiro c(m);
	std::cout << "Total do restaurante c : " << c.calculaTotalRestaurante() << std::endl;
}