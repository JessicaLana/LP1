#ifndef TELEVISAO 
#define TELEVISAO
class Televisao{
	unsigned int volume;
	int canal;	
	public:
	Televisao(int canal_, int volume_);
	unsigned int getVolume();
	int getCanal();
	void proxCanal();
	void antCanal();
	void maisVolume();
	void menosVolume();
	void setCanal(int n);
	void setVolume(unsigned int n);
};
#endif