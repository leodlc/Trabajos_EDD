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
#include "Operacion.h"
template <typename T>
void Operacion<T>::sumaFracciones(Fraccion<T> frac1, Fraccion<T> frac2, Fraccion<T> fracResultado)
{
	float tempFrac1Num = frac1.getNum(), tempFrac2Num = frac2.getNum(), tempFrac1Den = frac1.getDen(), tempFrac2Den = frac2.getDen();
	fracResultado.setNum(tempFrac1Num * tempFrac2Den + tempFrac2Num * tempFrac1Den);
	fracResultado.setDen(tempFrac1Den * tempFrac2Den);
	fracResultado.imprimir();
}

template class Operacion<float>;
