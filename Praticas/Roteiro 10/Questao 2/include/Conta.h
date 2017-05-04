#include "IConta.h"
#include <string>
#include <exception>
class SaldoNaoDisponivelException : public std::exception{
	public: 
	const char* what(){
		return "Saldo nao disponivel";
	}
};
class Conta : public IConta{
	protected:
	std::string nomeCliente;
	std::string numeroConta;
	long double salarioMensal;
	long double saldo;
	long double limite;
	public:
	void definirLimite();
	Conta(){}
	Conta(std::string nomeCliente_, long double salarioMensal_, std::string numeroConta_, long double saldo_);
	void sacar(long double n);
	void depositar(long double n);
	long double getSalarioMensal();
	long double getSaldo();
	std::string getNomeCliente();
	std::string getNumeroConta();
	void setSalarioMensal(long double v);
	virtual long double getLimite();
	void setSaldo(long double v);
	void setNomeCliente(std::string n);
	void setNumeroConta(std::string n);	
	friend std::ostream& operator<< (std::ostream& os, Conta& conta){
		os << "Nome do cliente: " <<conta.getNomeCliente() << "\nSaldo: "<< conta.getSaldo() << std::endl;;
	}
};