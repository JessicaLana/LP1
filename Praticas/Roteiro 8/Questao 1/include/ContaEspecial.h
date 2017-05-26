#include "Conta.h"
class ContaEspecial : public Conta{
	public:
	void definirLimite();
	ContaEspecial(){}
	ContaEspecial(std::string nomeCliente_, long double salarioMensal_, std::string numeroConta_, long double saldo_) : Conta(nomeCliente_, salarioMensal_, numeroConta_, saldo_){
		definirLimite();
	}
	friend std::ostream& operator<< (std::ostream& os,ContaEspecial& conta){
		os << "Nome do cliente: " << conta.getNomeCliente() << "\nSaldo: "<<conta.getSaldo() << std::endl;
	}
};