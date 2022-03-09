/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTOR: Leonardo de la Cadena
*TEMA: Coreccion Prueba Conjunta Parcial 1
*FECHA DE CREACION : 01 DE DICIEMBRE DEL 2021
* *FECHA DE MODIFICACION : 02 DE DICIEMBRE DEL 2021

* */
#pragma once
#include "Nodo.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <functional>
using namespace std;
class Lista {
private:
	Nodo* cabeza;
	Nodo* cola;
public:
	Lista();
	bool vacio(void);
	void imprimir();
	int tamano();
	void eliminar(int);
	void insertarInicio(int);
	//void insertarInicio(string);
	void insertarFinal(int);
	//void insertarFinal(string);
	void insertarEntre(int, int);
	
	//void recorrer(std::function<void(Fecha)> callback);
};

