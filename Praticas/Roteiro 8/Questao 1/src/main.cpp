#include "../include/ContaEspecial.h"
using namespace std;
int main(){
	ContaEspecial vinicius{string("Vinicius"),1200,string("1234567"),1001000};
	cout << vinicius;
	cout << endl;
	vinicius.sacar(4500);
	vinicius.sacar(800000);
	cout << vinicius;
	cout << endl;
	vinicius.depositar(-12);
	cout << vinicius;
}