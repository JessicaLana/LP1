#include <iostream>
#include <string>
#include <vector>
using namespace std;
//////////////////////////////////////////////////////////////////////// Questao 1
class Data{
	int dia, mes, ano;
	public:
	void setDia(int  n) {
		if(n > 31 || n < 0) 
			cout << "Erro, dia invalido" << endl;
		else
			dia = n;
	}
	void setMes(int n){
		if(n > 12 || n < 1)
			cout << "Erro, mes invalido" << endl;
		else mes = n;
	}
	void setAno(int n){
		if(ano < 0)
			cout << "Erro, ano invalido" << endl;
		else 
			ano = n;
	}
	int getDia(){
		return dia;
	}
	int getMes(){
		return mes;
	}
	int getAno(){
		return ano;
	}
	Data(){	}
	Data(int dia_, int mes_, int ano_) : dia(dia_), mes(mes_), ano(ano_){ 
		setDia(dia_);
		setMes(mes_);
		setAno(ano_);
	}
	void avancarDia(){
		if(dia == 31){
			if(mes == 12){ //Caso dia seja 31 de dezembro
				ano++;
				dia = 1;
				mes = 1;
			}
			else{//Ultimo dia de cada mes
				dia = 1;
				mes++;
			}
		}
		else dia++;
	}
};
class DataTest{
	public:
	void main();
};
void DataTest::main(){
	Data foo;
	foo.setDia(31);
	foo.setMes(10);
	foo.setAno(1998);
	foo.avancarDia();
	cout << foo.getDia() << '\\' << foo.getMes() << '\\' << foo.getAno() << endl;
}
///////////////////////////////////////////////////////////////////////// Questao 2

class Invoice{
	int numero, quantidade;
	double preco;
	string descricao;
	public:
	Invoice(){}
	Invoice(int n, int q, double p, string d) : numero(n), preco(p), quantidade(q) ,descricao(d) {}
	void setNumero(int n){
		numero = n;
	}
	void setQuantidade(int n){
		quantidade = n;
	}
	void  setPreco(double n){
		preco = n;
	}
	void setDescricao(string s){
		descricao = s;
	}
	int getNumero(){
		return numero;
	}
	int getQuantidade(){
		return quantidade;
	}
	string getDescricao(){
		return descricao;
	}
	double getPreco(){
		return preco;
	}
	double getInvoiceAmount(){
		return quantidade*preco;
	}
};

class InvoiceTest{
	public:
	void main();
};
void InvoiceTest::main(){
		Invoice foo;
		foo.setNumero(123);
		foo.setQuantidade(10);
		foo.setDescricao("Bateria");
		foo.setPreco(5.25);
		cout << "Preco: " << foo.getPreco() << "\n\tQuantidade: " << foo.getQuantidade() << "\n\tDescricao: " <<  foo.getDescricao() << "\n\tNumero: " << foo.getNumero() << endl;
		cout << "\tFatura: " << foo.getInvoiceAmount() << endl; 
}
///////////////////////////////////////////////////////////////////////  Questao 3l
class Empregado{
	string nome, sobrenome;
	double salario;
	public:
	Empregado(){}
	Empregado(string nome_, string sobrenome_, double salario_) : salario(salario_), nome(nome_), sobrenome(sobrenome_) {}
	void setNome(string s){
		nome = s;
	}
	void setSobrenome(string s){
		sobrenome = s;
	}
	void setSalario(double n){
		if(n > 0)
			salario = n;
	}
	string getNome(){
		return nome;
	}
	string getSobrenome(){
		return sobrenome;
	}
	double getSalario(){
		return salario;
	}
};

class EmpregadoTest{
	public:
	void main();
};
void EmpregadoTest::main(){
	Empregado vinicius, jessica;
	vinicius.setNome("Vinicius");
	vinicius.setSobrenome("Misael");
	vinicius.setSalario(500);
	jessica.setNome("Jessica");
	jessica.setSobrenome("Lana");
	jessica.setSalario(1000);
	cout << "\tSalario anual de " << vinicius.getNome() << " : " << vinicius.getSalario()*12 << endl;
	cout << "\tSalario anual de " << jessica.getNome() << " : " << jessica.getSalario()*12 << endl;
	jessica.setSalario(jessica.getSalario()*1.1);
	cout << "\tApos aumento do salario de jessica:" << endl; 
	cout << "\tSalario anual de " << vinicius.getNome() << " : " << vinicius.getSalario()*12 << endl;
	cout << "\tSalario anual de " << jessica.getNome() << " : " << jessica.getSalario()*12 << endl;
}

/////////////////////////////////////////////////////////////////////////  Questao 4
class Pessoa{
	string nome;
	string telefone;
	int idade;
	public:
	Pessoa(){};
	Pessoa(string nome_) : nome(nome_){}
	Pessoa(string nome_, int idade_, string  telefone_) : nome(nome_), idade(idade_), telefone(telefone_){}
	void setNome(string s){
		nome = s;
	}
	void setTelefone(string s){
		telefone = s;
	}
	void setIdade(int n){
		if(idade > 0)
			idade = n;
		else
			cout << "Idade invalida" << endl;
	}
	int getIdade(){
		return idade;
	}
	string getTelefone(){
		return telefone;
	}
	string getNome(){
		return nome;
	}
};
class CadastroDePessoa{
	public:
	void main();
};
void CadastroDePessoa::main(){
	Pessoa vinicius("Vinicius", 18, "123456789");
	Pessoa jessica("Jessica", 28, "123456789");
	vinicius.setTelefone("91623455");
	cout << "\tNome: " << vinicius.getNome() << endl << "\tIdade: " << vinicius.getIdade() << endl << "\tTelefone: " << vinicius.getTelefone() << endl;
}
///////////////////////////////////////////////////////////////////////// Questao 5
class Despesas{
	double valor;
	string tipoDeGasto;
	public:
	Despesas(){}
	Despesas(int n, string s) : valor(n), tipoDeGasto(s) {}
	void setValor(double n){
		valor = n;
	}
	void setTipoDeGasto(string s){
		tipoDeGasto = s;
	}
	double getValor()
	{
		return valor;
	}
	string getTipo(){
		return tipoDeGasto;
	}
};
class ControleDeGastos{
	vector<Despesas> despesas;
	public:
	ControleDeGastos(){}
	void setDespesas(vector<Despesas> despesas_) {
		despesas = despesas_;
	}
	double calculaTotalDespesas(){
		int sum = 0;
		for(auto e : despesas) sum+= e.getValor();
		return sum;
	}
};
class ProgramaPricipalQ5{
	public:
	void main(){
		Despesas despesa1(100, "Comida");
		Despesas despesa2(200, "Lazer");
		ControleDeGastos meusGastos;
		vector<Despesas> vetor = {despesa1, despesa2};
		meusGastos.setDespesas(vetor);
		cout << "\tDespesas totais: " << meusGastos.calculaTotalDespesas() << endl;
	}
};
///////////////////////////////////////////////////////////////////////// Questao 6

class Pagamento{
	double salario;
	string nomeDoFuncionario;
	public:
	Pagamento(double salario_, string nome) : salario(salario_), nomeDoFuncionario(nome) {}
	void setSalario(double n){
		salario = n;
	}
	void setNome(string s){
		nomeDoFuncionario = s;
	}
	double getSalario(){
		return salario;
	}
	string getNome(){
		return nomeDoFuncionario;
	}
};
class ControleDePagamentos{
	vector<Pagamento> pagamentos;
	public:
	void setPagamentos(vector<Pagamento> pagamentos_){
		pagamentos = pagamentos_;
	}
	double calculaTotalPagamentos();
	bool existePagamentoParaFuncionario (string nomeFuncionario);
};
double ControleDePagamentos::calculaTotalPagamentos( ){
	double sum = 0;
	for(auto e : pagamentos) sum+= e.getSalario();
	return sum;
}
bool ControleDePagamentos::existePagamentoParaFuncionario (string nomeFuncionario){
	bool flag = 0;
	for(auto e : pagamentos){
		if(e.getNome() ==nomeFuncionario) flag = 1;
	}
	return flag;
}
class ProgramaPrincipalQ6{
	public:
	int main();
};
int ProgramaPrincipalQ6::main(){
	ControleDePagamentos controle;
	Pagamento pagamento1(520, "VInicius");
	Pagamento pagamento2(1000, "Jessica");
	controle.setPagamentos({pagamento1, pagamento2});
	cout << "\tTotal de pagamentos: R$" << controle.calculaTotalPagamentos() << endl;
}

/////////////////////////////////////////////////////////////////////////
int main(){
	int opcao;
	cout << "Entre com a questao a ser resolvida: ";
	cin >> opcao;
	while(true){
		switch(opcao){
			case 1:
				DataTest bar;
				cout << "Metodo main de uma instancia de DataTest criando objeto foo do tipo Data; dia, mes e ano setados para (31,10,1998), respectivamente; foo.avancarDia() chamado.\nEstado final de foo (data,mes,ano):\n\t" ;
				bar.main();
				cout << "\nEntre com a questao a ser resolvida: " ;
				cin >> opcao;
				break;
			case 2:
				InvoiceTest bar1;
				cout << "Metodo main de um instancia de InvoiceTest criando objeto foo do tipo Invoice; Numero, quantidade, descriçao e preco setados para 123,10,\"Bateria\" e 5.25, respectivamente; imprimindo campos a partir dos gets:\n\t";
				bar1.main();
				cout << "\nEntre com a questao a ser resolvida: ";
				cin >> opcao;
				break;
			case 3:
				EmpregadoTest bar2;
				cout << "Metodo main de uma instancia de EmpregadoTest criando dois objetos do tipo Empregado: vinicius(\"Vinicius\",\"Misael\", 500 ) e jessica(\"Jessica\", \"Lana\", 1000), com atributos inicializados a partir dos metodos set." << endl;
				cout << "Imprimindo campos:" << endl;
				bar2.main();
				cout << "\nEntre com a questao a ser resolvida: ";
				cin >> opcao;
				break;
			case 4:
				CadastroDePessoa bar3;
				cout << "Metodo main de uma instancia de CadastroDePessoa criando dois objetos: vinicius{\"Vinicius\", 18, \"123456789\"} e jessica{\"Jessica\", 28, \"123456789\"}; vinicius.setTelefone(\"91623455\") apos construcao de vinicius; campos de vinicius sendo impressos utilizando dos metodos get:" << endl;
				bar3.main();
				cout << "\nEntre com a questao a ser resolvida: ";
				cin >> opcao;
				break;
			case 5:
				ProgramaPricipalQ5 bar4;
				cout << "Instanciadas duas Despesas: despesa1{100,\"Comida\"} e despesa2{100, \"Lazer\"}" << endl << "Criado objeto meusGastos do tipo ControleDeGastos; criado vetor<Despesas>{despesa1,despesa2} e passado como argumento para meusGastos.setDespesas(); imprimindo despesas: " << endl;
				bar4.main();
				cout << "\nEntre com a questao a ser resolvida: ";
				cin >> opcao;
				break;
			case 6: 
				ProgramaPrincipalQ6 bar5;
				cout <<  "Instanciando ControleDePagamentos; dois objetos Pagamento sendo construidos: pagamento1(520, \"Vinicius\") e pagamento2(1000, \"Jessica\")" << endl << "Chamada ControleDePagamentos::setPagamentos com argumentos pagamento1 e pagamento2" << endl;
				bar5.main();
				cout << "\nEntre com a questao a ser resolvida: ";
				cin >> opcao;
				break;
			default:
				cout << "Erro, tente novamente: " ;
				cin >> opcao;
				break;
		}
	}
}
