#include "Pedido.h"
void Pedido::setDescricao(std::string s){
	descricao = s;
}
void Pedido::setNumero(int n){
	numero = n;
}
void Pedido::setQuantidade(int n){
	quantidade = n;
}
void Pedido::setPreco(double p){
	preco = p;
}
std::string Pedido::getDescricao(){
	return descricao;
}
int Pedido::getNumero(){
	return numero;
}
int Pedido::getQuantidade(){
	return quantidade;
}
double Pedido::getPreco(){
	return preco;
}
Pedido::Pedido(int n, std::string d, int q, double p){
	numero = n;
	descricao = d;
	quantidade = q;
	preco = p;
}