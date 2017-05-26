#include "FiguraGeometrica.h"
class Quadrado : public FiguraGeometrica{
	double aresta;
	public:
	Quadrado(){
		setNome(std::string("Quadrado"));
	}
	Quadrado(double n): aresta(n){
		setNome(std::string("Quadrado"));
	}
	void setAresta(double n);
	double getAresta();
	double calcularArea();
};