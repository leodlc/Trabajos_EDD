// Examen3P_LDLC.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Matriz.h"

using namespace std;
int buscarBinariop(int numero_decimal)
{
	if (numero_decimal == 0)
		return 0;
	else
		return (numero_decimal % 2 + 10 *
			buscarBinariop(numero_decimal / 2));
}
int main(int argc, char** argv) {
	int d;
	cout << "Ingrese el tamanio de las matrices: ";
	cin >> d;
	Matriz m1;
	Matriz matrizBinaria;
	Matriz matmp;
	m1.setDimension(d);
	m1.segmentar();
	m1.encerar();
	m1.ingresar();
	m1.imprimir();
	printf("\n\n");
	//cout << "Prueba de funcion" << endl;
	///*int nump = 15;
	//cout<<buscarBinariop(nump)<<endl;*/

	return 0;
}
