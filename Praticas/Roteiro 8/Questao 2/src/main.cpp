#include "../include/Terreno.h"
#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include <vector>
int main(){
	Casa casa1(Endereco("Logradouro1", "Bairro1", "Cidade1", "Cep1",57), 3, 2, 45,30);
	Casa casa2(Endereco("Logradouro2", "Bairro2", "Cidade2", "Cep2", 56), 3, 5, 50,29);
	Terreno terreno1(100, Endereco("Logradouro3", "Bairro3", "Cidade3", "Cep3", 58));
	Terreno terreno2(200, Endereco("Logradouro4", "Bairro4", "Cidade4", "Cep4", 59));
	Apartamento apartamento1("Posicao1", 60500, 34, Endereco("Logradouro5", "Bairro5", "Cidade5", "Cep5", 60));
	std::vector<Imovel*>  vetor = {&casa1, &casa2, &terreno1, &terreno2, &apartamento1};
	for(auto e : vetor){
		e->getDescricao();
		std::cout<<"--------------------------------------------------------------------" << std::endl;
	}
} 