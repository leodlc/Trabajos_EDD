#pragma once
#include <iostream>
#include <stdlib.h>
#define TAMANO 1000
using namespace std;
/*Estructura para construir un arbol-B para indicar una tabla de 1000 registros por el
campo valor.*/
class stclave {
public:
	int valor;
	long registro;
};
class bnodo {
public:
	bnodo(int nClaves);
	~bnodo();
private:
	int clavesUsadas;
	stclave* clave;
	bnodo** puntero;
	bnodo* padre;
	friend class btree;
};