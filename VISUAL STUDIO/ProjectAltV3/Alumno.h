/***********************************************************************
 /** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
 * Module:  Alumno.h
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

class Alumno : public Persona
{
public:
   float getNotaAdquirida(void);
   void setNotaAdquirida(float newNotaAdquirida);
   Alumno();
   void verNotas(string);
   float getNota1();
   void setNota1(float);
   float getNota2();
   void setNota2(float);
   float getNota3();
   void setNota3(float);
   string getNombreAsignatura();
   void setNombreAsignatura(string);
   string getNombreProfesor();
   void setNombreProfesor(string);
   
protected:
private:
	float nota1;
	float nota2;
	float nota3;
	string nombreAsignatura;
	string nombreProfesor;
   float notaAdquirida;


};

