#ifndef RELOGIO
#define RELOGIO
class Relogio{
	int hora;
	int minuto;
	int segundo;
	public:
	int getHora();
	int getMinuto();
	int getSegundo();
	void setHora(int h);
	void setMinuto(int m);
	void setSegundo(int s);
	void setHorario(int h, int  m,  int s);
	void avancarHorario();
	Relogio(int h, int m, int s);

};
#endif