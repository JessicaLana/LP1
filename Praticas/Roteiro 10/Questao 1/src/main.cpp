#include "../include/TestaValidaNumero.h"
#include <iostream>
using namespace std;
int main(){
	TestaValidaNumero a;
	try{
		a.validaNumero(1003);
		a.validaNumero(3);
		a.validaNumero(103);
	}
	catch(ValorAcimaException& error){
		cout << error.what() << endl;
	}
	catch(ValorAbaixoException& error){
		cout << error.what() << endl;
	}
	catch(ValorMuitoAcimaException& error){
		cout << error.what() << endl;
	}
}