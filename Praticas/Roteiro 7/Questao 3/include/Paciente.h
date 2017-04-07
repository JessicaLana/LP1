//	Classe nao demandada na lista de atividades, porem o metodo Medico::realizarAtendimento() nao faz sentido sem um argumento que seja
//dessa classe ou algo semelhante, pois em uma situaçao real esse metodo geraria um prontuario etc.
// Como implementaçao nao foi pedida, essa classe foi pensada apenas como placeholder, nao sendo necessario  desenvolvimento pleno.
#ifndef PACIENTE 
#define PACIENTE 
#include <iostream>
class Prontuario{
	std::string info; //Deveria ser um arquivo json/yalm/xml/outros
	public:
	Prontuario(){}
	Prontuario(std::string info_) : info(info_){}
	static std::string gerarProntuario(std::string s) {
		std::cout << "Protuario gerado" << std::endl;
		return std::string("Foo");
	}; //Deveria gerar prontuario estuturado a partir de string com formataçao especifica
	void atualizarInfo(Prontuario p){};//Deveria modificar info atual com base em nova info
};
class Paciente{
	std::string nome;
	Prontuario prontuario;
	public:
	Paciente(){}
	Paciente(std::string nome_, Prontuario pt) : prontuario(pt), nome(nome_){}
	void atualizarProntuario(std::string atendimento);
	void atualizarProntuario(Prontuario novoProntuario);
};
#endif