// Tarea2_LatinSquare.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "LatinSquare.h"
using namespace std;
int main()
{
	LatinSquare lsquare;
	int dimension;
	
	do {
		if (dimension <= 1) {
			cout << "La dimension debe ser mayor a 1"<<endl;
		}
		cout << "Ingrese la dimension del cuadrado:";
		cin >> dimension;
	} while (dimension >= 2);
	lsquare.obtainSquare(dimension);

	return 0;
}

