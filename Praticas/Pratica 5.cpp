#include <iostream>
#include <string>
#include <vector>
using namespace std;
/////////////////////////////////////////////////////////////////////////
class Data{
	int dia, mes, ano;
	public:
	Data(){}
	Data(int dia_, int mes_, int ano_) : dia(dia_), mes(mes_), ano(ano_){ 
		if(dia > 31 || dia < 0)
			cout << "Erro, dia invalido" << endl;
		if(mes > 12 || mes < 1)
			cout << "Erro, mes invalido" << endl;
		if(ano < 0)
			cout << "Erro, ano invalido" << endl;
	}
	void setDia(int  n) {
		dia = n;
	}
	void setMes(int n){
		mes = n;
	}
	void setAno(int n){
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
/////////////////////////////////////////////////////////////////////////q
class DataTest{
	public:
	void main();
};
void DataTest::main(){
	Data foo;
	foo.setDia(13);
	foo.setMes(10);
	foo.setAno(1998);
	foo.avancarDia();
	cout << foo.getDia() << '\\' << foo.getMes() << '\\' << foo.getAno() << endl;
}
/////////////////////////////////////////////////////////////////////////
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
		cout << "Preco: " << foo.getPreco() << "\nQuantidade: " << foo.getQuantidade() << "\nDescricao: " <<  foo.getDescricao() << "\nNumero: " << foo.getNumero() << endl;
		cout << "\nFatura: " << foo.getInvoiceAmount() << endl; 
}
/////////////////////////////////////////////////////////////////////////
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
	cout << "Salario anual de " << vinicius.getNome() << " : " << vinicius.getSalario()*12 << endl;
	cout << "Salario anual de " << jessica.getNome() << " : " << jessica.getSalario()*12 << endl;
	jessica.setSalario(jessica.getSalario()*1.1);
	cout << "Apos aumento:" << endl; 
	cout << endl << "Salario anual de " << vinicius.getNome() << " : " << vinicius.getSalario()*12 << endl;
	cout << "Salario anual de " << jessica.getNome() << " : " << jessica.getSalario()*12 << endl;
}
/////////////////////////////////////////////////////////////////////////
class Pessoa{
	string nome;
	string telefone;
	int idade;
	public:
	Pessoa(){};
	Pessoa(string nome_) : nome(nome_){}
	Pessoa(string nome_, int idade_, string telefone_) : nome(nome_), idade(idade_), telefone(telefone_){}
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
	cout << vinicius.getNome() << endl << vinicius.getIdade() << endl << vinicius.getTelefone() << endl;
}
/////////////////////////////////////////////////////////////////////////
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
	}
};

int main(){

}


