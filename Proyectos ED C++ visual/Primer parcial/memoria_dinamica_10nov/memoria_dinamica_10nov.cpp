#include <iostream>
#include <stdlib.h>
#include <conio.h>
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
#include <stdio.h>
#include "Operaciones.h"

int main(int argc, char** argv) {
	int t;
	
	
	std::cout << "Ingrese el tamanio: " << std::endl;
	std::cin >> t;
	Operaciones<int> operacion(t);
	operacion.ingresar();
	operacion.imprimir();

	operacion.procesar();
	operacion.imprimir();
	return 0;
}
