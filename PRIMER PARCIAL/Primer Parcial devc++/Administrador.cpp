/***********************************************************************
 * Module:  Administrador.cpp
 * Author:  AsrockLeo
 * Modified: lunes, 29 de noviembre de 2021 21:05:00
 * Purpose: Implementation of the class Administrador
 ***********************************************************************/

#include "Administrador.h"

////////////////////////////////////////////////////////////////////////
// Name:       Administrador::getUsuario()
// Purpose:    Implementation of Administrador::getUsuario()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Administrador::getUsuario(void)
{
   return usuario;
}

////////////////////////////////////////////////////////////////////////
// Name:       Administrador::setUsuario(std::string newUsuario)
// Purpose:    Implementation of Administrador::setUsuario()
// Parameters:
// - newUsuario
// Return:     void
////////////////////////////////////////////////////////////////////////

void Administrador::setUsuario(std::string newUsuario)
{
   usuario = newUsuario;
}

////////////////////////////////////////////////////////////////////////
// Name:       Administrador::getContrasena()
// Purpose:    Implementation of Administrador::getContrasena()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Administrador::getContrasena(void)
{
   return contrasena;
}

////////////////////////////////////////////////////////////////////////
// Name:       Administrador::setContrasena(std::string newContrasena)
// Purpose:    Implementation of Administrador::setContrasena()
// Parameters:
// - newContrasena
// Return:     void
////////////////////////////////////////////////////////////////////////

void Administrador::setContrasena(std::string newContrasena)
{
   contrasena = newContrasena;
}

////////////////////////////////////////////////////////////////////////
// Name:       Administrador::Administrador()
// Purpose:    Implementation of Administrador::Administrador()
// Return:     
////////////////////////////////////////////////////////////////////////

Administrador::Administrador()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Administrador::~Administrador()
// Purpose:    Implementation of Administrador::~Administrador()
// Return:     
////////////////////////////////////////////////////////////////////////

Administrador::~Administrador()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Administrador::registrarAlumno()
// Purpose:    Implementation of Administrador::registrarAlumno()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Administrador::registrarAlumno(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Administrador::registroProfesor()
// Purpose:    Implementation of Administrador::registroProfesor()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Administrador::registroProfesor(void)
{
   // TODO : implement
}