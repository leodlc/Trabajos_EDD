/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTOR: Leonardo de la Cadena
*TEMA: Coreccion Prueba Conjunta Parcial 1
*FECHA DE CREACION : 01 DE DICIEMBRE DEL 2021
* *FECHA DE MODIFICACION : 02 DE DICIEMBRE DEL 2021

* */
#pragma once
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
class Nodo {
private:
	int dato;
	Nodo* anterior;
	Nodo* siguiente;
public:
	Nodo(void);
	Nodo(int, Nodo*, Nodo*);
	void setDato(int);
	int getDato(void);
	Nodo getSiguiente(void);
	void setSiguiente(Nodo*);
	Nodo getAnterior(void);
	void setAnterior(Nodo*);
	friend class Lista;

};

