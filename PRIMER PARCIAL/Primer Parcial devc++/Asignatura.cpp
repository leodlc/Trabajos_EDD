/***********************************************************************
 * Module:  Asignatura.cpp
 * Author:  AsrockLeo
 * Modified: lunes, 29 de noviembre de 2021 21:05:00
 * Purpose: Implementation of the class Asignatura
 ***********************************************************************/

#include "Alumno.h"
#include "Profesor.h"
#include "Asignatura.h"

////////////////////////////////////////////////////////////////////////
// Name:       Asignatura::getNombreAsignatura()
// Purpose:    Implementation of Asignatura::getNombreAsignatura()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Asignatura::getNombreAsignatura(void)
{
   return nombreAsignatura;
}

////////////////////////////////////////////////////////////////////////
// Name:       Asignatura::setNombreAsignatura(std::string newNombreAsignatura)
// Purpose:    Implementation of Asignatura::setNombreAsignatura()
// Parameters:
// - newNombreAsignatura
// Return:     void
////////////////////////////////////////////////////////////////////////

void Asignatura::setNombreAsignatura(std::string newNombreAsignatura)
{
   nombreAsignatura = newNombreAsignatura;
}

////////////////////////////////////////////////////////////////////////
// Name:       Asignatura::getProfesorAsignado()
// Purpose:    Implementation of Asignatura::getProfesorAsignado()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Asignatura::getProfesorAsignado(void)
{
   return profesorAsignado;
}

////////////////////////////////////////////////////////////////////////
// Name:       Asignatura::setProfesorAsignado(std::string newProfesorAsignado)
// Purpose:    Implementation of Asignatura::setProfesorAsignado()
// Parameters:
// - newProfesorAsignado
// Return:     void
////////////////////////////////////////////////////////////////////////

void Asignatura::setProfesorAsignado(std::string newProfesorAsignado)
{
   profesorAsignado = newProfesorAsignado;
}

////////////////////////////////////////////////////////////////////////
// Name:       Asignatura::getNRC()
// Purpose:    Implementation of Asignatura::getNRC()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Asignatura::getNRC(void)
{
   return NRC;
}

////////////////////////////////////////////////////////////////////////
// Name:       Asignatura::setNRC(std::string newNRC)
// Purpose:    Implementation of Asignatura::setNRC()
// Parameters:
// - newNRC
// Return:     void
////////////////////////////////////////////////////////////////////////

void Asignatura::setNRC(std::string newNRC)
{
   NRC = newNRC;
}

////////////////////////////////////////////////////////////////////////
// Name:       Asignatura::Asignatura()
// Purpose:    Implementation of Asignatura::Asignatura()
// Return:     
////////////////////////////////////////////////////////////////////////

Asignatura::Asignatura()
{
   alumno = NULL;
   profesor = NULL;
}

////////////////////////////////////////////////////////////////////////
// Name:       Asignatura::~Asignatura()
// Purpose:    Implementation of Asignatura::~Asignatura()
// Return:     
////////////////////////////////////////////////////////////////////////

Asignatura::~Asignatura()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Asignatura::calcularNotaFinal()
// Purpose:    Implementation of Asignatura::calcularNotaFinal()
// Return:     float
////////////////////////////////////////////////////////////////////////

float Asignatura::calcularNotaFinal(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Asignatura::aprobacion()
// Purpose:    Implementation of Asignatura::aprobacion()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Asignatura::aprobacion(void)
{
   // TODO : implement
}