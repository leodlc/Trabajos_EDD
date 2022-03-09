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
#include <iostream>
#include "Fraccion.h"
#include "Operacion.h"

int main(int, char**)
{

    Fraccion<float> frac1;
    Fraccion<float> frac2;
    Fraccion<float> frac3;
    Fraccion<float> fracResultado;
    float x;

    std::cout << "Ingrese el numerador de la primera fraccion: ";
    std::cin >> x;
    frac1.setNum(x);
    std::cout << "Ingrese el denominador de la primera fraccion: ";
    std::cin >> x;
    frac1.setDen(x);
    std::cout << "Ingrese el numerador de la segunda fraccion: ";
    std::cin >> x;
    frac2.setNum(x);
    std::cout << "Ingrese el denominador de la segunda fraccion: ";
    std::cin >> x;
    frac2.setDen(x);
    std::cout << "El reultado es -> ";

    frac1.imprimir();
    std::cout << " + ";
    frac2.imprimir();
    std::cout << " = ";
    Operacion<float> operacion;
    operacion.sumaFracciones(frac1, frac2, fracResultado);
    return 0;
}
