/***********************************************************************
 /** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
 * Module:  Profesor.h
 * Author:  *Cristian Maranje
*Leonardo de la Cadena
*Johnny Loachamin
*Alvaro Zumba
  * Modified: Domingo, 21 de noviembre de 2021
 * Purpose: Division Clases Grupo
 ***********************************************************************/
//Cristian Maranje

#pragma once
#include <iostream>
#include <string>
#include "Persona.h"
#include "Asignatura.h"
#include "Alumno.h"
using namespace std;
class Profesor : public Persona
{
public:
   Asignatura getAsignaturaImpartida(void);
   void setAsignaturaImpartida(Asignatura newAsignaturaImpartida);
   float getNotaAsignada(void);
   void setNotaAsignada(float newNotaAsignada);
   Profesor();
   //~Profesor();
   Alumno getAlumno(void);
   void setAlumno(Alumno newAlumno);
   void ingresarNotaP1(void);
   void ingresarNotaP2(void);
   void ingresarNotaP3(void);

protected:
private:
   Asignatura asignaturaImpartida;
   float notaAsignada;
   Alumno alumno;


};

