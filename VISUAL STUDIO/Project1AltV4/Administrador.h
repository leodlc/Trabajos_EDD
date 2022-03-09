/***********************************************************************
 * Module:  Administrador.h
 * Author:  AsrockLeo
 * Modified: lunes, 29 de noviembre de 2021 21:04:27
 * Purpose: Declaration of the class Administrador
 ***********************************************************************/
#pragma once
#include <iostream>
#include <string>
#include "Profesor.h"
#include <stdlib.h>
#include "ListaCircularDoble.h"
#include "validaciones.h"

using namespace std;

class Administrador
{
public:
	std::string getUsuario(void);
	void setUsuario(std::string newUsuario);
	std::string getContrasena(void);
	void setContrasena(std::string newContrasena);
	Administrador();
	~Administrador();
	Alumno registrarAlumno(void);
	Profesor registroProfesor(void);
	void pantallaAdmin(void);


protected:
private:
	std::string usuario;
	std::string contrasena;


};


