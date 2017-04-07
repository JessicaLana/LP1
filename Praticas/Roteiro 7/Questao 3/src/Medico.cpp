#include "../include/Medico.h"
std::string Medico::getNome(){
	return nome;
}
double Medico::getAltura(){
	return altura;
}
double Medico::getPeso(){
	return peso;
}
void Medico::setNome(std::string nome_){
	nome = nome_;
}
void Medico::setAltura(double altura_){
	altura = altura_;
}
void Medico::setPeso(double peso_){
	peso = peso_;
}