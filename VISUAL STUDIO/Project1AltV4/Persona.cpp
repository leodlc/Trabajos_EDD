/***********************************************************************
 /** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
 * Module:  Persona.cpp
 * Author:  *Cristian Maranje
*Leonardo de la Cadena
*Johnny Loachamin
*Alvaro Zumba
  * Modified: Domingo, 21 de noviembre de 2021
 * Purpose: Division Clases Grupo
 ***********************************************************************/

#include "Persona.h"
using namespace std;

Persona::Persona()
{
	this->cedula = 0;
	this->apellido = "";
	this->contrasena = "";
	this->correo = "";
	this->ID = "";
	this->nombre = "";
	this->usuario = "";
}


//Persona::~Persona()
//{
//
//}

string Persona::getUsuario(void) {
	return usuario;
}

void Persona::setUsuario(string newUsuario) {
	this->usuario = newUsuario;
}

string Persona::getContrasenaa(void) {
	return contrasena;
}

void Persona::setContrasena(string newContrasena) {
	this->contrasena = newContrasena;
}

std::string Persona::getNombre(void)
{
	return nombre;
}



void Persona::setNombre(std::string newNombre)
{
	nombre = newNombre;
}


std::string Persona::getApellido(void)
{
	return apellido;
}


void Persona::setApellido(std::string newApellido)
{
	apellido = newApellido;
}


string Persona::getID(void)
{
	return ID;
}


void Persona::setID(std::string newID)
{
	ID = newID;
}


long int Persona::getCedula(void)
{
	return cedula;
}


void Persona::setCedula(long int newCedula)
{
	cedula = newCedula;
}



std::string Persona::getCorreo(void)
{
	return correo;
}


void Persona::setCorreo(std::string newCorreo)
{
	correo = newCorreo;
}



void Persona::generarCorreoUsuario(int cont)
{
	string localNombre = nombre;
	string localApellido = apellido;

	for (int i = 0; i < localNombre.length(); i++)
		localNombre[i] = tolower(localNombre[i]);
	for (int i = 0; i < localApellido.length(); i++)
		localApellido[i] = tolower(localApellido[i]);
	if (cont == 0)
	{
		correo = localNombre[0] + localApellido + "@espe.edu.ec";
		usuario = localNombre[0] + localApellido;
	}
	else
	{
		correo = localNombre[0] + localApellido + to_string(cont) + "@espe.edu.ec";
		usuario = localNombre[0] + localApellido + to_string(cont);
	}
}
