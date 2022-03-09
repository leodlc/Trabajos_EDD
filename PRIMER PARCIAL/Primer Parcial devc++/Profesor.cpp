/***********************************************************************
 * Module:  Profesor.cpp
 * Author:  AsrockLeo
 * Modified: lunes, 29 de noviembre de 2021 21:05:00
 * Purpose: Implementation of the class Profesor
 ***********************************************************************/

#include "Profesor.h"

////////////////////////////////////////////////////////////////////////
// Name:       Profesor::getAsignaturaImpartida()
// Purpose:    Implementation of Profesor::getAsignaturaImpartida()
// Return:     Asignatura
////////////////////////////////////////////////////////////////////////

Asignatura Profesor::getAsignaturaImpartida(void)
{
   return asignaturaImpartida;
}

////////////////////////////////////////////////////////////////////////
// Name:       Profesor::setAsignaturaImpartida(Asignatura newAsignaturaImpartida)
// Purpose:    Implementation of Profesor::setAsignaturaImpartida()
// Parameters:
// - newAsignaturaImpartida
// Return:     void
////////////////////////////////////////////////////////////////////////

void Profesor::setAsignaturaImpartida(Asignatura newAsignaturaImpartida)
{
   asignaturaImpartida = newAsignaturaImpartida;
}

////////////////////////////////////////////////////////////////////////
// Name:       Profesor::getNotaAsignada()
// Purpose:    Implementation of Profesor::getNotaAsignada()
// Return:     float
////////////////////////////////////////////////////////////////////////

float Profesor::getNotaAsignada(void)
{
   return notaAsignada;
}

////////////////////////////////////////////////////////////////////////
// Name:       Profesor::setNotaAsignada(float newNotaAsignada)
// Purpose:    Implementation of Profesor::setNotaAsignada()
// Parameters:
// - newNotaAsignada
// Return:     void
////////////////////////////////////////////////////////////////////////

void Profesor::setNotaAsignada(float newNotaAsignada)
{
   notaAsignada = newNotaAsignada;
}

////////////////////////////////////////////////////////////////////////
// Name:       Profesor::Profesor()
// Purpose:    Implementation of Profesor::Profesor()
// Return:     
////////////////////////////////////////////////////////////////////////

Profesor::Profesor()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Profesor::~Profesor()
// Purpose:    Implementation of Profesor::~Profesor()
// Return:     
////////////////////////////////////////////////////////////////////////

Profesor::~Profesor()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Profesor::getAlumno()
// Purpose:    Implementation of Profesor::getAlumno()
// Return:     Alumno
////////////////////////////////////////////////////////////////////////

Alumno Profesor::getAlumno(void)
{
   return alumno;
}

////////////////////////////////////////////////////////////////////////
// Name:       Profesor::setAlumno(Alumno newAlumno)
// Purpose:    Implementation of Profesor::setAlumno()
// Parameters:
// - newAlumno
// Return:     void
////////////////////////////////////////////////////////////////////////

void Profesor::setAlumno(Alumno newAlumno)
{
   alumno = newAlumno;
}

////////////////////////////////////////////////////////////////////////
// Name:       Profesor::ingresarNotaP1()
// Purpose:    Implementation of Profesor::ingresarNotaP1()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Profesor::ingresarNotaP1(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Profesor::ingresarNotaP2()
// Purpose:    Implementation of Profesor::ingresarNotaP2()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Profesor::ingresarNotaP2(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Profesor::ingresarNotaP3()
// Purpose:    Implementation of Profesor::ingresarNotaP3()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Profesor::ingresarNotaP3(void)
{
   // TODO : implement
}