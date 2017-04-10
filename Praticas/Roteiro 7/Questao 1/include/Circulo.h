#include "FiguraGeometrica.h"
class Circulo : public FiguraGeometrica{
	double raio;
	public:
	Circulo(){
		setNome("Circulo");
	}
	Circulo(double raio_) : raio(raio_){
		setNome("Circulo");
	}
	double calcularArea();
	void setRaio(double n);
	double getRaio();
};