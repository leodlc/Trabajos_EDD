/***********************************************************************
 /** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
 * Modulo:  Profesor.cpp
 * Autores:  *Cristian Maranje
*Leonardo de la Cadena
*Johnny Loachamin
*Alvaro Zumba
  * Modified: Domingo, 21 de noviembre de 2021
 * Purpose: Division Clases Grupo
 ***********************************************************************/

#include "Profesor.h"
using namespace std;
Profesor::Profesor()
{
	this->alumno = Alumno();
	this->asignaturaImpartida = Asignatura();
	this->notaAsignada = 0.0f;
}


//Profesor::~Profesor()
//{
//
//}

Asignatura Profesor::getAsignaturaImpartida(void)
{
   return asignaturaImpartida;
}


void Profesor::setAsignaturaImpartida(Asignatura newAsignaturaImpartida)
{
   asignaturaImpartida = newAsignaturaImpartida;
}


float Profesor::getNotaAsignada(void)
{
   return notaAsignada;
}


void Profesor::setNotaAsignada(float newNotaAsignada)
{
   notaAsignada = newNotaAsignada;
}

Alumno Profesor::getAlumno(void)
{
   return alumno;
}


void Profesor::setAlumno(Alumno newAlumno)
{
   alumno = newAlumno;
}


void Profesor::ingresarNotaP1(void)
{
   
}


void Profesor::ingresarNotaP2(void)
{
  
}


void Profesor::ingresarNotaP3(void)
{
   
}
void menuProfeosr() {

	cout << "\n\t\tCUENTA ADMIN\n\n";
	cout << " 1. INGRESAR NOTAS ALUMNO              " << endl;
	cout << " 2. SALIR                " << endl;



	cout << "\n INGRESE OPCION: ";

}
//void Profesor::pantallaProfe(void) {
//	int opc;
//	do {
//		system("cls");
//		menuAdmin();
//
//		cin >> opc;
//		switch (opc) {
//		case 1:
//			cout << "Ingresar el dato a insertar: ";
//
//			break;
//		case 2:
//			cout << "Ingresar el dato a insertar: ";
//
//			break;
//		case 3:
//
//			break;
//		}
//		system("pause");
//	} while (opc != 3);
//
//
//}