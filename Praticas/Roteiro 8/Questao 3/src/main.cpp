#include "../include/Assalariado.h"
#include "../include/Horista.h"
#include "../include/Comissionado.h"
#include "../include/SistemaGerenciarFolha.h"
using namespace std;
int main(){
	Assalariado foo(string("Foo"), 69, 420.0);
	Comissionado bar(string("Bar"), 42, 15.0, 19.0, 700.0);
	Horista baz(string("Baz"), 13, 18.0, 911.0);

	cout<< "Funcionarios instanciados:\n" << endl;
	cout << "Assalariado:\n" << foo <<"-------------------------------------" << endl;
	cout << "Comissionado:\n" <<bar << "Salario: " << bar.calculaSalario() <<  "\n-------------------------------------" << endl;
	cout << "Horista:\n" << baz << "Salario: " << baz.calculaSalario() << "\n-------------------------------------\n" << endl;

	vector<Funcionario*> funcionarios = {&foo, &bar, &baz};
	SistemaGerenciarFolha sistema(funcionarios);

	cout << "Retorno de sistema.calcularValorTotalFolha(): " << sistema.calcularValorTotalFolha() << endl;
	cout << "Retorno de sistema.consultaSalarioFuncionario(13)" << sistema.consultaSalarioFuncionario(13) << endl;
}