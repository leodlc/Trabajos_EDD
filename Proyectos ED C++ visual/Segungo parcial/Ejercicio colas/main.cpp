/**************************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*TITULO: DEBER 1 - EJERCICIOS COLAS
*AUTOR(ES): LUIS CUEVA, CHRISTIAN ANDRANGO, ARIEL JARA. JORGE PAUCAR, JORGE AGUAS
*FECHA: JUEVES 11 DE DICIEMBRE DE 2021
*VERSION: 1
*ESTRUCTURA DE DATOS
*NRC: 7166
***************************************************************************/
#include <iostream>
#include "nodo.h"
#include "cola.h"
#include <iomanip>
#include <stdio.h>
using namespace std;
int main() {
	Cola<int>* nueva_cola = new Cola<int>;
	int dato, opcion = 0;

	do
	{
		cout << "\t PROGRAMA PRINCIPAL COLA\t" << endl;
		cout << "1. EncolarClientes" << endl;
		cout << "2. estaVacia" << endl;
		cout << "3. Desencolar " << endl;
		cout << "4. Mostrar" << endl;
		cout << "5. Salir" << endl;
		cout << "Seleccione una opcion" << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			cout << "DIGITE EL NUMERO DE CLIENTES QUE INGRESARAN AL BANCO: ";
			cin >> dato;
			nueva_cola->encolar(dato);
			break;
		case 2:
				nueva_cola->estaVacia();
			break;
		case 3:
			cout << "Desencolando......... ";
			nueva_cola->desencolar();
			nueva_cola->mostrar();
			break;
		case 4:
			nueva_cola->mostrar();
			break;
		default:
			break;
		}
	} while (opcion != 5);
	system("pause");
}
