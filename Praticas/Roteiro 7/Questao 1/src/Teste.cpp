#include "../include/Teste.h"
#include <iostream>
void Teste::main(){
	Quadrado a(12);
	Triangulo b(2,3);
	Circulo c(1);
	std::cout << "Area do quadrado " << a.calcularArea() << std::endl;
	std::cout << "Area do triangulo " << b.calcularArea() << std::endl;
	std::cout << "Area do circulo " << c.calcularArea() << std::endl;
}