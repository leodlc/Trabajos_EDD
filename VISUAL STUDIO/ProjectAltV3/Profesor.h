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
#include "Archivo.h"
#include "Validaciones.h"
using namespace std;
class Profesor : public Persona
{
public:
   string getAsignaturaImpartida(void);
   void menuProfesor();
   void pantallaProfe(string);
   void setAsignaturaImpartida(string newAsignaturaImpartida);
   float getNotaAsignada(void);
   void setNotaAsignada(float newNotaAsignada);
   Profesor();
   //~Profesor();
   float ingresarNotaP1(void);
   float ingresarNotaP2(void);
   float ingresarNotaP3(void);
   float calcularNotaFinal(float,float,float);

protected:
private:
   string asignaturaImpartida;
   float notaAsignada;


};

