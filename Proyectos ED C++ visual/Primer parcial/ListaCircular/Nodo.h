#pragma once
#include<stdlib.h>

class Nodo {
public:
	Nodo(int);
	int getDato();
	void setDato(int);
	Nodo* getSiguiente();
	void setSiguiente(Nodo*);
	Nodo* getAnterior();
	void setAnterior(Nodo*);
private:
	int dato;
	Nodo* siguiente;
	Nodo* anterior;
	
};