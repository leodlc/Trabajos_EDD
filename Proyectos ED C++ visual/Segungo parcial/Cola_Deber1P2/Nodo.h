/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES: Cristian Maranje
*Leonardo de la Cadena
*Johnny Loachamin
*Alvaro Zumba
*TEMA: Cola de banco
*FECHA DE CREACION : 12 DE DICIEMBRE DEL 2021
*FECHA DE MODIFICACION: 13 DE DICIEMBRE DE 2021
* */
#pragma once

#include <iostream>
#include <stdlib.h>
using namespace std;
template <class T>
class Nodo
{
private:
	Nodo* siguiente;
	T dato;
public:
	Nodo();
	~Nodo();
	void establecerDato(T);
	T obtenerDato(void);
	Nodo* obtenerSiguiente(void);
	void establecerSiguiente(Nodo*);
};
template < class T>
Nodo<T>::Nodo() {
	siguiente = NULL;
	dato = 0;
}
template <class T>
void Nodo<T>::establecerDato(T value) {
	dato = value;
}
template <class T>
T Nodo<T>::obtenerDato() {
	return dato;
}
template <class T>
void Nodo<T>::establecerSiguiente(Nodo* item) {
	siguiente = item;
}
template <class T>
Nodo<T>* Nodo<T>::obtenerSiguiente() {
	return siguiente;
}
