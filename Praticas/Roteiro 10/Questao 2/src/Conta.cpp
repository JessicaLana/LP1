#include "../include/Conta.h"
#include <exception>

void Conta::definirLimite(){
	limite = 2*salarioMensal;
}
Conta::Conta(std::string nomeCliente_, long double salarioMensal_, std::string numeroConta_, long double saldo_){
	setNomeCliente(nomeCliente_);
	setSalarioMensal(salarioMensal_);
	setNumeroConta(numeroConta_);
	setSaldo(saldo_);
	definirLimite();
}
long double Conta::getSalarioMensal(){
	return salarioMensal;
}
long double Conta::getSaldo(){
	return saldo;
}
long double Conta::getLimite(){
	return limite;
}
std::string Conta::getNomeCliente(){
	return nomeCliente;
}
std::string Conta::getNumeroConta(){
	return numeroConta;
}
void Conta::setSalarioMensal(long double n){
	salarioMensal = n;
}
void Conta::setSaldo(long double n){
	saldo = n;
}
void Conta::setNomeCliente(std::string n){
	nomeCliente = n;
}
void Conta::setNumeroConta(std::string n){
	numeroConta = n;
}
void Conta::sacar(long double n){
	if(saldo >= n)
		saldo -= n;
	else if(saldo+limite > n)
		saldo -= n;
	else
		throw SaldoNaoDisponivelException();
}
void Conta::depositar(long double n){
	if(n >= 0)
		saldo += n;
	else 
		std::cerr << "Erro: Depositando valor negativo" << std::endl;
}
