/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES: Cristian Maranje
*Leonardo de la Cadena
*Johnny Loachamin
*Alvaro Zumba
*TEMA: Manejo de memoria dinamica con templates
*FECHA DE CREACION : 10 DE NOVIEMBRE DEL 2021
*FECHA DE MODIFICACION: 11 DE NOVIEMBRE DE 2021
* */
#pragma once
#include <iostream>
using namespace std;
template <class T>
class Operaciones
{
private:
	T* p;
	T t;

public:
	Operaciones(T t);
	void ingresar();
	void imprimir();
	void procesar();

};

