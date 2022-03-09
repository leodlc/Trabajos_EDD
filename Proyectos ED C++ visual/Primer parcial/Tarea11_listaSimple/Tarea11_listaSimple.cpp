// Tarea11_listaSimple.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "Lista.h"

using namespace std;

int main(int argc, char** argv) {
	Lista lst;
	lst.insertar(3);
	lst.insertar(13);
	lst.insertar(23);
	lst.insertar(33);
	lst.insertar(43);
	lst.mostrar();
	return 0;
}



