#pragma once
#include <iostream>

using namespace std;

template <class T>
class Puntaje;
template <typename T>
ostream& operator <<(ostream& o, const Puntaje<T>& A);
template <class T>
class Puntaje
{
public:
	Puntaje(T practica, T  teorica , T participacion, T notaFinal);
	//Puntaje();
	~Puntaje();
	void setPractica(T practica);
	void setTeorica(T img);
	void setParticipacion(T img);
	T getPractica();
	T getTeorica();
	T getParticipacion();
	T calcNotaPractica();
	T calcNotaTeorica();
	T calcNotaParticipacion();

	Puntaje<T>& operator +(const Puntaje<T>& A);
	//Puntaje<T>& operator -(const Puntaje<T>& A);
private:
	T practica;
	T teorica;
	T participacion;
	T notaFinal;
};

