/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTOR: Leonardo de la Cadena
*TEMA: Coreccion Prueba Conjunta Parcial 1
*FECHA DE CREACION : 01 DE DICIEMBRE DEL 2021
* *FECHA DE MODIFICACION : 02 DE DICIEMBRE DEL 2021

* */
#include "Nodo.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
void Nodo::setDato(int newDato) {
	dato = newDato;
}

int Nodo::getDato(void) {
	return dato;
}

Nodo Nodo::getAnterior(void) {
	return *anterior;
}

void Nodo::setAnterior(Nodo* newAnterior) {
	anterior = newAnterior;
}

Nodo Nodo::getSiguiente(void) {
	return *siguiente;
}

void Nodo::setSiguiente(Nodo* newSiguiente) {
	siguiente = newSiguiente;
}

Nodo::Nodo() {
	dato = 0;
	siguiente = NULL;
	anterior = NULL;
}

Nodo::Nodo(int newDato, Nodo* newSiguiente, Nodo* newAnterior) {
	dato = newDato;
	siguiente = newSiguiente;
	anterior = newAnterior;
}
