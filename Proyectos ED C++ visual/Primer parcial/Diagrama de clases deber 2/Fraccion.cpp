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
#include "Fraccion.h"
template <typename T>
Fraccion<T>::Fraccion()
{
}
template <typename T>
Fraccion<T>::~Fraccion()
{
	// TODO : implement
}
template <typename T>
T Fraccion<T>::getNum(void)
{
	return num;
}
template <typename T>
void Fraccion<T>::setNum(T newNum)
{
	num = newNum;
}
template <typename T>
T Fraccion<T>::getDen(void)
{
	return den;
}
template <typename T>
void Fraccion<T>::setDen(T newDen)
{
	den = newDen;
}
template <typename T>
void Fraccion<T>::imprimir()
{
	std::cout << num << "/" << den;
}
template class Fraccion<float>;
