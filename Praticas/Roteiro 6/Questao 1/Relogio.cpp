#include "Relogio.h"

int Relogio::getHora(){
	return hora;
}
int Relogio::getMinuto(){
	return minuto;
}
int  Relogio::getSegundo(){
	return segundo;
}
void  Relogio::setHora(int h){
	if(h >= 0 && h <= 24){
		hora = h;
	}
}
void  Relogio::setMinuto(int m){
	if(m >= 0 && m <= 60){
		minuto = m;
	}
}
void  Relogio::setSegundo(int s){
		if(s >= 0 && s <= 60){
		segundo = s;
	}
}
void  Relogio::setHorario(int h, int  m,  int s){
	setHora(h);
	setMinuto(m);
	setSegundo(s);
}
void Relogio::avancarHorario(){
	if(segundo == 59){
		if(minuto == 59){
			if(hora == 24){
				hora = 0;
				segundo = 0;
				minuto = 0;
			}
			else {
				hora ++;
				minuto = 0;
				segundo = 0;
			}
		}
		else{
			minuto ++;
			segundo = 0;
		}
	}
	else segundo++;
}
 Relogio::Relogio(int h, int m, int s){
	setHora(h);
	setMinuto(m);
	setSegundo(s);
 }
