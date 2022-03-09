/***********************************************************************
 /** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
 * Module:  MainProyecto.cpp
 * Author:  *Cristian Maranje
*Leonardo de la Cadena
*Johnny Loachamin
*Alvaro Zumba
  * Modified: Domingo, 21 de noviembre de 2021
 * Purpose: Division Clases Grupo
 ***********************************************************************/
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Alumno.h"
#include "Archivo.h"
#include "Asignatura.h"
#include "Profesor.h"
#include "Persona.h"
#include "Login.h"
#include "Administrador.h"
using namespace std;

void MenuPrincipal();

int main() {
	string opc;
	int cont = 0;
	ListaCircularDoble listaProfesor;
	ListaCircularDoble listaAlumno;
	Archivo archivo;
	

	do{
		system("cls");
		MenuPrincipal();
		getline(cin >> ws, opc);
		opc = validarOpcMenu(opc, 4);
		switch (stoi(opc)) {
			case 1:
			login();
			break;
			case 2:
				listaAlumno = archivo.leerArchivoAlumno("Alumnos.txt");
				if (listaAlumno.estaVacia()) {
					cout << "Lista vacia primero ingrese datos." << endl;
				}
				else {
					cout << "-------LISTA DE ALUMNOS-------" << endl;
					listaAlumno.recorrer([&](Alumno alumno) {
						++cont;
						cout << "El usuario del Alumno-> " << cont << " es: " << alumno.getNombre() << endl;
						});
					cont = 0;
				}
			break;
			case 3:
			{
				listaProfesor = archivo.leerArchivoProfesor("Profesores.txt" );
				if ( listaProfesor.estaVacia( ) ) {
					cout << "Lista vacia primero ingrese datos." << endl;
				}
				else {
					cout << "-------LISTA DE PROFESORES-------" << endl;
					listaProfesor.recorrer( [ & ]( Profesor profesor ) {
						++cont;
						cout << "El usuario del Profesor-> " << cont << " es: " << profesor.getNombre( ) << endl;

						} );
					cont = 0;
				}
				break;
			}
			case 4:
				exit(1);
			break;

		}
		system("pause");
	} while (true);
	return 0;
}

void MenuPrincipal() {
	cout << "		Menu Principal " << endl;
	cout << "1. Login. " << endl;
	cout << "2. Mostrar nombres de usuario alumnos. " << endl;
	cout << "3. Mostrar nombres de usuario Profesores. " << endl;
	cout << "4. Salir. " << endl;
	cout << "Ingrese opcion: ";
}