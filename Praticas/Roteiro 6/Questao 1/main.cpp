#include "Relogio.h"
#include <iostream>
using namespace std;

int main(){
	Relogio a(23,59,59);
	std::cout << a.getHora() << "  " << a.getMinuto() << "  " << a.getSegundo() << std::endl;
	a.avancarHorario();
	std::cout << a.getHora() << "  " << a.getMinuto() << "  " << a.getSegundo() << std::endl;
	a.avancarHorario();
	std::cout << a.getHora() << "  " << a.getMinuto() << "  " << a.getSegundo() << std::endl;
	a.avancarHorario();
	std::cout << a.getHora() << "  " << a.getMinuto() << "  " << a.getSegundo() << std::endl;
	}