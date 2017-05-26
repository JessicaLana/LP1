#ifndef ICONTA
#define CONTA
#include <iostream>
class IConta{
	public:
	virtual void sacar(long double valor) = 0;
	virtual void depositar(long double valor) = 0;
};
#endif