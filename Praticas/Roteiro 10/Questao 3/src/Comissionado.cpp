#include "../include/Comissionado.h"
double Comissionado::calculaSalario(){
	return salarioBase + (vendasSemanais * percentualComissao);
}
double Comissionado::getVendas(){
	return vendasSemanais;
}
double Comissionado::getPercentual(){
	return percentualComissao;
}
void Comissionado::setVendas(double n){
	vendasSemanais = n;
}
void Comissionado::setPercentual(double n){
	percentualComissao = n;
}