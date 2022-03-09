#include "Puntaje.h"

#include <iostream>

using namespace std;
template <class T>
Puntaje<T>::Puntaje(T practica, T  teorica, T participacion, T notaFinal) {
	this->practica = practica;
	this->teorica = teorica;
	this->participacion = participacion;
	this->notaFinal = notaFinal;

}
//template <class T>
//Puntaje<T>::Puntaje() {
//	
//
//}
template <class T>
Puntaje<T>::~Puntaje() {

}

template <class T>
void Puntaje<T>::setPractica(T practica) {
	this->practica = practica;
}
template <class T>
void Puntaje<T>::setTeorica(T teorica) {
	this->teorica = teorica;
}
template <class T>
void Puntaje<T>::setParticipacion(T participacion) {
	this->participacion = participacion;
}

template <class T>
T Puntaje<T>::getPractica() {
	//this->practica *= 0.30;
	return this->practica;
}

template <class T>
T Puntaje<T>::getTeorica() {
	//this->teorica *= 0.60;
	return this->teorica;
}
template <class T>
T Puntaje<T>::getParticipacion() {
	//this->participacion *= 0.10;
	return this->participacion;
}
template <class T>
Puntaje<T>& Puntaje<T>::operator +(const Puntaje<T>& A) {
	this->practica += A.practica;
	this->teorica += A.teorica;
	this->participacion += A.participacion;
	

	return *this;
}
template <class T>
T Puntaje<T>::calcNotaPractica() {
	//practica *= 0.30;
	return practica *= 0.30;
}
template <class T>
T Puntaje<T>::calcNotaTeorica() {
	//teorica *= 0.60;
	return teorica *= 0.60;
}
template <class T>
T Puntaje<T>::calcNotaParticipacion() {
	//participacion *= 0.10;
	return participacion *= 0.10;
}


template class Puntaje<int>;
template class Puntaje<float>;
template class Puntaje<double>;