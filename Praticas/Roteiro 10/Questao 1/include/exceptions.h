#ifndef EXCEPTIONS
#include <exception>
#define EXCEPTIONS

class ValorAbaixoException : public std::exception{
	public: 
	const char* what(){
		return "Valor menor igual a 0";
	}
};
class ValorAcimaException : public std::exception{
	public:
	const char* what(){
		return "Valor entre 100 e 1000";
	}
};
class ValorMuitoAcimaException : public std::exception{
	public: 
	const char* what(){
		return "Valor acima de 1000";
	}
};
#endif