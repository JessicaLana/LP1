#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <map>
using namespace std;
/*
	Vinicius Misael Mendes de Moura
	Jessica Lana Ricardo da Silva Braga
*/
int q1(){
	int tmp, maior;
	cout << "Continue entrando com numeros inteiros (0 para parar) " << endl;
	cin >> maior;
	if(maior == 0)
		return 1;
	while(cin >> tmp){
		if(tmp == 0) 
			break;
		else if(tmp > maior)
			maior = tmp;
	}
	cout << "O maior numero entrado foi " << maior << endl;
	return 1;
}

void q2(){
	srand(time(0));
	int random = rand()%100;
	int tmp;
	cout << "Adivinhe o numero entre um e 100" << endl;
	while(cin >> tmp){
		if(tmp > random) 
			cout << "Numero grande demais" << endl;
		else if(tmp < random)
			cout << "Numero pequeno demais" << endl;
		else {
			cout << "Parabens, voce adivinhou o numero" << endl;
			break;
		}
	}
}

void q3(){
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 5);
	map<int,int> sides{};
	float n, tmp;
	cout << "Entre com o numero de lançamentos a serem feitos" << endl;
	cin >> n;
	for(int i = 0; i < n; i++){
		tmp = dis(gen);
		sides[tmp]++;
	}
	for(int i = 0; i < 6; i++){
		cout << "Face " << i << ": " << (sides[i]/n)*100.0 << endl;
	}
}


void q4(){
	map<int, int> camisas{};
	int tmp, total = 0;
	cout << "Enquete: Quem foi o melhor jogador?" << endl;
	while(true){
		cout << "Numero do jogador (0=fim) : ";
		cin >> tmp;
		if(tmp == 0)
			break;
		else if(tmp >= 1 && tmp <= 23){
			camisas[tmp]++;
			total++;
		}
		else	
			cout << "Numero invalido" << endl;
	}

	cout << "Resultado da votaçao" << endl;
	cout<< "Foram computados " << total << " votos." << endl;
	cout << "Jogador\tVotos\t%" << endl;
	for(auto e : camisas){
		cout << e.first << "\t" << e.second << "\t" << e.second/(float)total*100 << "%" << endl;
	}
}

int main(){
	int opcao;
	cout << "Entre com a questao a ser resolvida" << endl;
	cin >> opcao;
	while(true){
		switch(opcao){
			case 1:
				q1();
				cout << "\nEntre com a questao a ser resolvida" << endl;
				cin >> opcao;
				break;
			case 2:
				q2();
				cout << "\nEntre com a questao a ser resolvida" << endl;
				cin >> opcao;
				break;
			case 3:
				q3();
				cout << "\nEntre com a questao a ser resolvida" << endl;
				cin >> opcao;
				break;
			case 4:
				q4();
				cout << "\nEntre com a questao a ser resolvida" << endl;
				cin >> opcao;
				break;
		}
	}
}