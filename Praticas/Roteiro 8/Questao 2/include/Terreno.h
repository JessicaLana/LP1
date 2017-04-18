#include "Imovel.h"
class Terreno : public Imovel{
	double area;
	public:
	Terreno(){}
	Terreno(double n, Endereco e) : Imovel(e), area(n){}
	void setArea(double n);
	double getArea();
	void getDescricao();
};