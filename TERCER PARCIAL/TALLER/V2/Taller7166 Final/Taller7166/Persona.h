/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES: 
*
*Adrian Paez
*Juan Gallardo
*Leonardo de la Cadena
*TEMA: TALLER DE RECUPERACION - REGISTRO DE AUTOS
*FECHA DE CREACION : 26 DE FEBRERO DEL 2022
*FECHA DE MODIFICACION: 26 DE FEBRERO DEL 2022
* */
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Persona
{

private:
	string nombre;
	string apellido;
	string cedula;
	Persona* siguiente;

public:
	Persona(string, string, string);
	string getNombre();
	void setNombre(string);

	string getApellido();
	void setApellido(string);

	string getCedula();
	void setCedula(string);

	Persona* getSiguiente();
	void setSiguiente(Persona*);

	friend class ListaPersona;

};
Persona::Persona(string _nombre, string _apellido, string _cedula) {
	this->nombre = _nombre;
	this->apellido = _apellido;
	this->cedula = _cedula;
	this->siguiente = NULL;
}

string Persona::getNombre()
{
	return this->nombre;
}

void Persona::setNombre(string _nombre)
{
	this->nombre = _nombre;
}

string Persona::getApellido()
{
	return this->apellido;
}

void Persona::setApellido(string _apellido)
{
	this->apellido = _apellido;
}

string Persona::getCedula()
{
	return this->cedula;
}

void Persona::setCedula(string _cedula)
{
	this->cedula = _cedula;
}

Persona* Persona::getSiguiente()
{
	return this->siguiente;
}

void Persona::setSiguiente(Persona* _siguiente)
{
	this->siguiente = _siguiente;
}