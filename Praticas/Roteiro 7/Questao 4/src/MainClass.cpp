#include "../include/MainClass.h"
#include <iostream>
using namespace std;
void MainClass::main(){
	TrabalhadorAssalariado bob(string("Bob"), 25);
	TrabalhadorPorHora frank(string("Frank"), 10);
	cout << "Salario de Frank, assalariado, com 60 horas de trabalho: "	<< frank.calcularPagamento(60) << endl;
	cout << "Salario de Bob, por hora, com 60 horas de trabalho: "	<< frank.calcularPagamento(35) << endl;
}