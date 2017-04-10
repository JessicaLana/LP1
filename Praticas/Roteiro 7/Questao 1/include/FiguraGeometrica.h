#ifndef FIGURA_GEOMETRIA
#define FIGURA_GEOMETRIA	
#define PI 3.141592
#include <string>
#include <cmath>
class FiguraGeometrica{
	std::string nome;
	public:
	virtual double calcularArea() = 0;
	void setNome(std::string n);
	std::string getNome();
};
#endif