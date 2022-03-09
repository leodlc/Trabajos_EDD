/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTOR: Leonardo de la Cadena
*TEMA: Coreccion Prueba Conjunta Parcial 1
*FECHA DE CREACION : 01 DE DICIEMBRE DEL 2021
* *FECHA DE MODIFICACION : 02 DE DICIEMBRE DEL 2021

* */
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Fecha.h"
#include "Lista.h"
#include "Nodo.h"
#include "Validar.h"

using namespace std;

void menu() {
	cout << "\n\t\tCALCULO DE EDAD\n\n";
	cout << " 1. INSERTAR  FECHA               " << endl;
	cout << " 2. INSERTAR FECHA AL FINAL                " << endl;
	cout << " 3. MOSTRAR LISTA DE EDADES                    " << endl;
	cout << " 4. INSERTAR ENTRE                   " << endl;
	cout << " 5. ELIMINAR ELEMENTO                " << endl;
	cout << " 6. SALIR                            " << endl;

	cout << "\n INGRESE OPCION: ";
}

int main()
{
	int opc, newDato;
	Fecha fecha;
	int dia = fecha.getDiaAct();
	int mes = fecha.getMesAct();
	int anio = fecha.getAnioAct();
	int diaNac = fecha.getDiaNac();
	int mesNac = fecha.getMesNac();
	int anioNac = fecha.getAnioNac();
	bool respuesta;
	Lista list;
	
	
	do {
		system("cls");
		menu();
		cin >> opc;
		switch (opc) {
		case 1:
			cout << " FECHA  ACTUAL" << endl;
			cout << "Ingrese Anio Actual: ";   cin >> anio;
			validarDato(anio);
			cout << "Ingrese Mes Actual: ";   cin >> mes;
			validarDato(mes);
			cout << "Ingrese Dia Actual: ";  cin >> dia;
			validarDato(dia);
			respuesta = validarLosDias(dia, mes,anio);
			
			if (respuesta == true) {
				cout << " FECHA DE NACIMIENTO" << endl;
				cout << "Ingrese Anio Nacimiento: ";  cin >> anioNac;
				validarDato(anioNac);
				cout << "Ingrese Mes de Nacimiento: ";  cin >> mesNac;
				validarDato(mesNac);
				cout << "Ingrese Fecha de Nacimiento: ";  cin >> diaNac;
				validarDato(diaNac);
				respuesta = validarLosDias(diaNac, mesNac,anioNac);
				//list.insertarInicio(fecha.fechaUnida(dia, mes, anio));
				//list.insertarInicio(fecha.fechaUnida(dia, mes, anio, diaNac, mesNac, anioNac));
				list.insertarInicio(fecha.calcularEdad(dia, mes, anio, diaNac, mesNac, anioNac));
				break;
			}
			else {
				cout << "Ha ingresado mal los datos, intente de nuevo" << endl;
				
				break;
			}
			break;
			
			

			
		case 2:
			cout << " FECHA  ACTUAL" << endl;
			cout << "Ingrese Anio Actual: ";   cin >> anio;
			validarDato(anio);
			cout << "Ingrese Mes Actual: ";   cin >> mes;
			validarDato(mes);
			cout << "Ingrese Dia Actual: ";  cin >> dia;
			validarDato(dia);
			respuesta = validarLosDias(dia, mes, anio);
			if (respuesta == true) {
				cout << " FECHA DE NACIMIENTO" << endl;
				cout << "Ingrese Anio Nacimiento: ";  cin >> anioNac;
				validarDato(anioNac);
				cout << "Ingrese Mes de Nacimiento: ";  cin >> mesNac;
				validarDato(mesNac);
				cout << "Ingrese Fecha de Nacimiento: ";  cin >> diaNac;
				validarDato(diaNac);
				respuesta = validarLosDias(diaNac, mesNac, anioNac);
				list.insertarFinal(fecha.calcularEdad(dia, mes, anio, diaNac, mesNac, anioNac));
				break;
			}
			else {
				cout << "Ha ingresado mal los datos, intente de nuevo" << endl;

				break;
			}
			break;
		case 3:
			cout << "LISTA DE EDADES" << endl;
			list.imprimir();
			break;
		case 4:
			int pos;
			cout << " FECHA  ACTUAL" << endl;
			cout << "Ingrese Anio Actual: ";   cin >> anio;
			validarDato(anio);
			cout << "Ingrese Mes Actual: ";   cin >> mes;
			validarDato(mes);
			cout << "Ingrese Dia Actual: ";  cin >> dia;
			validarDato(dia);
			respuesta = validarLosDias(dia, mes, anio);
			if (respuesta == true) {
				cout << " FECHA DE NACIMIENTO" << endl;
				cout << "Ingrese Anio Nacimiento: ";  cin >> anioNac;
				validarDato(anioNac);
				cout << "Ingrese Mes de Nacimiento: ";  cin >> mesNac;
				validarDato(mesNac);
				cout << "Ingrese Fecha de Nacimiento: ";  cin >> diaNac;
				validarDato(diaNac);

				respuesta = validarLosDias(diaNac, mesNac, anioNac);
				cout << "Ingrese la posicion de la lista en donde desea ingresar" << endl;
				cin >> pos;
				list.insertarEntre(fecha.calcularEdad(dia, mes, anio, diaNac, mesNac, anioNac),pos);
				break;
			}
			else {
				cout << "Ha ingresado mal los datos, intente de nuevo" << endl;

				break;
			}
			break;
			
			
			
		case 5:
			cout << "Ingrese la posicion que quiere eliminar: ";
			cin >> pos;
			list.eliminar(pos);
			break;
		case 6:

			break;
		}
		system("pause");
	} while (opc != 6);

	
}
    


