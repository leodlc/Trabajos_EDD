// ExamenFinal3P.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Matriz.h"

using namespace std;

int main(int argc, char** argv) {
	int d;
	cout << "Ingrese el tamanio de las matrices: ";
	cin >> d;

	Matriz<int> m1(d);
	/*Matriz<int> m2(d);
	Matriz<int> mr(d);*/


	m1.segmentar();
	//m2.segmentar();
	//mr.segmentar();

	m1.encerar();
	//m2.encerar();
	//mr.encerar();

	m1.ingresar();
	//m2.ingresar();

	m1.imprimir();
	printf("\n\n");
	//m2.imprimir();

	/*cout << "\nLa multiplicacion de las matrices es: \n";
	mr = m1.procesar(m2);
	mr.imprimir();
	printf("\n\n");*/

	return 0;
}