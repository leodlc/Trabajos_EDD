/***********************************************************************
 /** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
 * Module:  Alumno.cpp
 * Author:  *Cristian Maranje
*Leonardo de la Cadena
*Johnny Loachamin
*Alvaro Zumba
  * Modified: Domingo, 21 de noviembre de 2021
 * Purpose: Division Clases Grupo
 ***********************************************************************/

#include "Alumno.h"
#include "Asignatura.h"
using namespace std;

Alumno::Alumno()
{
	this->notaAdquirida = 0.0f;
}



//Alumno::~Alumno()
//{
//
//}

//Asignatura Alumno::getListaAsignatura(void)
//{
//   return listaAsignatura[10];
//}
//
//
//
//void Alumno::setListaAsignatura(Asignatura newListaAsignatura)
//{
//   listaAsignatura[10] = newListaAsignatura;
//}



float Alumno::getNotaAdquirida(void)
{
   return notaAdquirida;
}


void Alumno::setNotaAdquirida(float newNotaAdquirida)
{
   notaAdquirida = newNotaAdquirida;
}

void Alumno::verNotas(void)
{
   
}