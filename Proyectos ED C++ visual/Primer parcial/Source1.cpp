/*
* ESTE PROGRAMA CALCULA EL PRECIO DE UN PRODUCTO AGREGANDO EL IMPUESTA DEL IVA DEL 12%
* 
*/
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Producto.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	float valorInicial, valorIva=12;
	string nombre;
	cout << "*******Registro de productos********" << endl;
	cout << "Ingrese el nombre del producto: " ; 
	cin >> nombre;
	cout << "Ingrese el valor del producto: " ;
	cin >> valorInicial;
	Producto <float> producto(valorInicial,valorIva);

	cout << "El precio del producto " << nombre << " es: " << producto.calc() << endl;
	
	return 0;
}