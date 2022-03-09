/***********************************************************************
 * Module:  Alumno.cpp
 * Author:  AsrockLeo
 * Modified: lunes, 29 de noviembre de 2021 21:05:00
 * Purpose: Implementation of the class Alumno
 ***********************************************************************/

#include "Alumno.h"

////////////////////////////////////////////////////////////////////////
// Name:       Alumno::getListaAsignatura()
// Purpose:    Implementation of Alumno::getListaAsignatura()
// Return:     Asignatura
////////////////////////////////////////////////////////////////////////

Asignatura Alumno::getListaAsignatura(void)
{
   return listaAsignatura;
}

////////////////////////////////////////////////////////////////////////
// Name:       Alumno::setListaAsignatura(Asignatura newListaAsignatura)
// Purpose:    Implementation of Alumno::setListaAsignatura()
// Parameters:
// - newListaAsignatura
// Return:     void
////////////////////////////////////////////////////////////////////////

void Alumno::setListaAsignatura(Asignatura newListaAsignatura)
{
   listaAsignatura = newListaAsignatura;
}

////////////////////////////////////////////////////////////////////////
// Name:       Alumno::getNotaAdquirida()
// Purpose:    Implementation of Alumno::getNotaAdquirida()
// Return:     float
////////////////////////////////////////////////////////////////////////

float Alumno::getNotaAdquirida(void)
{
   return notaAdquirida;
}

////////////////////////////////////////////////////////////////////////
// Name:       Alumno::setNotaAdquirida(float newNotaAdquirida)
// Purpose:    Implementation of Alumno::setNotaAdquirida()
// Parameters:
// - newNotaAdquirida
// Return:     void
////////////////////////////////////////////////////////////////////////

void Alumno::setNotaAdquirida(float newNotaAdquirida)
{
   notaAdquirida = newNotaAdquirida;
}

////////////////////////////////////////////////////////////////////////
// Name:       Alumno::Alumno()
// Purpose:    Implementation of Alumno::Alumno()
// Return:     
////////////////////////////////////////////////////////////////////////

Alumno::Alumno()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Alumno::~Alumno()
// Purpose:    Implementation of Alumno::~Alumno()
// Return:     
////////////////////////////////////////////////////////////////////////

Alumno::~Alumno()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Alumno::verNotas()
// Purpose:    Implementation of Alumno::verNotas()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Alumno::verNotas(void)
{
   // TODO : implement
}