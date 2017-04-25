#include "../include/Assalariado.h"
#include "../include/Horista.h"
#include "../include/Comissionado.h"
using namespace std;
int main(){
	Assalariado foo(string("Foo"), 69, 420.0);
	Comissionado bar(string("Bar"), 42, 15.0, 19.0, 700.0);
	Horista baz(string("Baz"), 13, 18.0, 911.0);

	cout << "Exemplo de Assalariado:\n\n" << foo << "Retorno de foo.calculaSalario(): " << foo.calculaSalario() << "\n-------------------------------------" << endl;
	cout << "Exemplo de Comissionado:\n\n" <<bar << "Retorno de foo.calculaSalario(): " << bar.calculaSalario() << "\n-------------------------------------" << endl;
	cout << "Exemplo de Horista:\n\n" <<baz << "Retorno de foo.calculaSalario(): " << baz.calculaSalario() << "\n-------------------------------------" << endl;
}