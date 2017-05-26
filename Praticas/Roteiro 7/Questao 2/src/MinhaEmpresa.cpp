#include "../include/MinhaEmpresa.h"
#include <iostream>
void MinhaEmpresa::main(){
	Funcionario vinicius(std::string("12345"), std::string("Vinicius"), 1200);
	Consultor jessica(std::string("54321"), std::string("Jessica"), 2000);
	std::cout << "Salario do funcionario Vinicius: R$" << vinicius.getSalario() << std:: endl;
	std::cout << "Salario da consultora Jessica: R$" << jessica.getSalario() << std:: endl;

	std::cout << "Salario da consultora Jessica com mais um aumento de 30%: R$" << jessica.getSalario(30) << std:: endl;

}