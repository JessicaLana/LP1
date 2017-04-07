#include "../include/Hospital.h"
#include <vector>
int Hospital::main(){
	Paciente foo(std::string("Foo Bar"), Prontuario());
	Otorrino oto(std::string("Oto"), 1.75, 85);
	Oftamologista ofto(std::string("Ofto"), 1.90, 86);
	Ginecologista gine(std::string("Gineco"), 2, 120); 
	Cirurgiao cirus(std::string("Cirus"), 1.60, 72);

	std::vector<Medico*> medicos{&oto, &ofto, &gine, &cirus};
	for(Medico* e : medicos){
		e->realizarAtendimento(foo);
		std::cout << "Atendimento feito por medico com seguinte especializaçao: " << e->getNomeCurso() << "\n"<<std::endl;
	}
	
}