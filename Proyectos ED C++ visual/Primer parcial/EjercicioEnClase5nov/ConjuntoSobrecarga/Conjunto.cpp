#include "Conjunto.h"
#include <iostream>

using namespace std;

template <class T>
Conjunto<T>::Conjunto(T elemento[]) {
	this->elemento = elemento;
	
}
template <class T>
Conjunto<T>::~Conjunto() {

}

template <class T>
void Conjunto<T>::setElementos(T elemento[]) {
	this->elemento = elemento[;
}


template <class T >
int Conjunto<T>::getElementos() {
	return this->elemento;
}





template <class T>
Conjunto<T>& Conjunto<T>::operator ==(const Conjunto<T>& A) {
	this-> elemento == A.elemento;
	
	return *this;
}
template class Conjunto<int>;
template class Conjunto<float>;
template class Conjunto<double>;

