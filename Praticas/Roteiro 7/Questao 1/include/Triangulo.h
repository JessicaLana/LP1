#include "FiguraGeometrica.h"
class Triangulo : public FiguraGeometrica{
	double base, altura;
	public:
	Triangulo() {
		setNome(std::string("Triangulo"));
	}
	Triangulo(double base_,double altura_) :  base(base_), altura(altura_){
		setNome(std::string("Triangulo"));
	}
	double calcularArea();
	void setAltura(double n);
	void setBase(double n);
	double getAltura();
	double getBase();
};