#include "TelevisaoTeste.h"
#include <iostream>
void TelevisaoTeste::main(){
	Televisao a(3,15);
	Televisao b(6,20);
	a.maisVolume();
	a.menosVolume();
	a.proxCanal();
	a.antCanal();
	b.maisVolume();
	b.setCanal(12);
	b.proxCanal();
	std::cout << "B tem como canal " << b.getCanal()  << " e volume " << b.getVolume() << std::endl;
	std::cout << "A tem como canal " << a.getCanal()  << " e volume " << a.getVolume() << std::endl;
}

int main(){
	TelevisaoTeste tv;
	tv.main();
}