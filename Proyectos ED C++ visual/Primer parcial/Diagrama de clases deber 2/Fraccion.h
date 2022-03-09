/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES: Cristian Maranje
*Leonardo de la Cadena
*Johnny Loachamin
*Alvaro Zumba
*TEMA: CREACION DE UN PROGRAMA DE SUMA DE FRACCIONES<>
*FECHA DE CREACION : 27 DE OCTUBRE DEL 2021
*FECHA DE MODIFICACION: 28 DE OCTUBRE 2021
* */
/***********************************************************************
 * Module:  Operacion.cpp
 * Author:  crisl
 * Modified: 27 October, 2021 9:23:31 PM
 * Purpose: Implementation of the class Operacion
 ***********************************************************************/
#pragma once
#include <iostream>

template<typename T>
class Fraccion
{
public:
	Fraccion();
	~Fraccion();
	T getNum(void);
	void setNum(T newNum);
	T getDen(void);
	void setDen(T newDen);
	void imprimir();

protected:
private:
	T num = 0;
	T den = 1;
};

