/***********************************************************************
 /** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
 * Module:  Persona.h
 * Author:  *Cristian Maranje
*Leonardo de la Cadena
*Johnny Loachamin
*Alvaro Zumba
  * Modified: Domingo, 21 de noviembre de 2021
 * Purpose: Division Clases Grupo
 ***********************************************************************/

 //Alvaro Zumba
#pragma once
#include <iostream>
#include <string>

using namespace std;
class Persona
{
public:
	string getNombre(void);
	void setNombre(string newNombre);
	string getUsuario(void);
	void setUsuario(string newUsuario);
	string getContrasenaa(void);
	void setContrasena(string newContrasena);
	string getApellido(void);
	void setApellido(string newApellido);
	string getID(void);
	void setID(string newID);
	long int getCedula(void);
	void setCedula(long int  newCedula);
	void generarCorreoUsuario(int);
	string getCorreo(void);
	void setCorreo(string newCorreo);
	Persona();
	
	//~Persona();

protected:
private:
	string usuario;
	string contrasena;
	string nombre;
	string apellido;
	string ID;
	long int  cedula;
	string correo;
};

