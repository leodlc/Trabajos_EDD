/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES: Cristian Maranje
*Leonardo de la Cadena
*Johnny Loachamin
*Alvaro Zumba
*TEMA: Cola de banco
*FECHA DE CREACION : 12 DE DICIEMBRE DEL 2021
*FECHA DE MODIFICACION: 13 DE DICIEMBRE DE 2021
* */
#include <iostream>
#include "Tiempo.h"
#include "Nodo.h"
#include "Cola.h"
#include <stdio.h>
using namespace std;
int main() {
	Cola<int>* nuevaCola = new Cola<int>;
	int dato, opcion = 0;

	do
	{
		cout << "============PROGRAMA PRINCIPAL COLA================" << endl;
		cout << "1. ENCOLAR CLIENTES" << endl;
		cout << "2. COMPROBAR SI ESTA VACIO" << endl;
		cout << "3. DESENCOLAR " << endl;
		cout << "4. MOSTRAR" << endl;
		cout << "5. SALIR" << endl;
		cout << "Seleccione una opcion" << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			cout << "DIGITE EL NUMERO DE CLIENTES QUE INGRESARAN AL BANCO: ";
			cin >> dato;
			nuevaCola->encolar(dato);
			break;
		case 2:
			nuevaCola->estaVacia();
			break;
		case 3:
			cout << "Desencolando......... ";
			nuevaCola->desencolar();
			nuevaCola->mostrar();
			break;
		case 4:
			nuevaCola->mostrar();
			break;
		default:
			break;
		}
	} while (opcion != 5);
	system("pause");
}