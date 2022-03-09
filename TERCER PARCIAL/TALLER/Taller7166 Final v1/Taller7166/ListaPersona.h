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
#include "Persona.h"
#include <conio.h>
#include <fstream>

using namespace std;

class ListaPersona {

private:
	Persona* primero;
	Persona* actual;

public:
	ListaPersona();
	//void insertarTXT();
	void inicializarListaP(Persona*&);
	void insertar(Persona*&, string, string, string);
	void insertarNuevo(Persona*&, string, string, string);
	int compare(string, string);
	bool buscar(Persona*, string);
	void imprimirUno(Persona*, string);
	void imprimir(Persona*);

};

ListaPersona::ListaPersona()
{
	this->primero = NULL;
}

void ListaPersona::inicializarListaP(Persona*& personas)
{
	string line;
    fstream out;
    out.open("listaPersona.txt", fstream::in);
    ifstream myfile("listaPersona.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
	
			string _nombre = line.substr(0, line.find(","));
			string tmp = line.substr(line.find(",") + 1, line.length());
			string _apellido = tmp.substr(0, tmp.find(","));
			string _cedula = tmp.substr(tmp.find(",") + 1, tmp.length());
			insertar(personas, _nombre, _apellido, _cedula);

		}
		myfile.close();
		out.close();
	}
}

void ListaPersona::insertar(Persona*& personas, string _nombre, string _apellido, string _cedula)
{
	Persona* nuevo = new Persona(_nombre, _apellido, _cedula);

	if (personas == NULL)
	{
		this->primero = nuevo;
		personas = nuevo;

	}
	else
	{
		this->actual->setSiguiente(nuevo);
	}

	this->actual = nuevo;

}

void ListaPersona::insertarNuevo(Persona*& personas, string _nombre, string _apellido, string _cedula)
{
	Persona* nuevo = new Persona(_nombre, _apellido, _cedula);
	if (personas == NULL)
	{
		this->primero = nuevo;
		personas = nuevo;
        fstream out("listaPersona.txt", fstream::app);
        if (out.is_open())
        {
            
			out << _nombre << "," << _apellido << "," << _cedula << "\n";
        }
        out.close();
	}
	else
	{
		insertarNuevo(this->actual->siguiente,_nombre, _apellido, _cedula);
	}
	this->actual = nuevo;
}

int ListaPersona::compare(string a, string b)
{
	const char* word1 = a.c_str();
	const char* word2 = b.c_str();
	int result = strcmp(word1, word2);
	return result;
}


bool ListaPersona::buscar(Persona* personas, string _cedula)
{
	bool existe = false;
	Persona* actual = personas;

	while (actual != NULL)
	{
		if (compare(actual->getCedula(), _cedula) == 0) existe = true;
		actual = actual->siguiente;
	}

	if (existe == true)
	{
		return existe;
	}
	else
	{
		return false;
	}
}

void ListaPersona::imprimirUno(Persona* personas, string _cedula)
{
	bool existe = false;
	Persona* actual = personas;
	Persona* tmp = NULL;
	Tools tool;

	while (actual != NULL || existe != true)
	{
		if (tool.compare(actual->cedula, _cedula) == 0)
		{
			tmp = actual;
			existe = true;
		}
		actual = actual->siguiente;
	}

	if (existe == true)
	{
		cout << "Nombre: " << tmp->nombre << endl;
		cout << "Apellido: " << tmp->apellido << endl;
		cout << "No. de cedula: " << tmp->cedula << endl;
		cout << endl;
		_getch();
	}
	else
	{
		cout << "Esa persona no esta registrada...";
		_getch();
	}
}

void ListaPersona::imprimir(Persona* personas)
{
	Persona* tmp = personas;
	if (tmp == NULL)
	{
		cout << "\n\nNO HAY LISTA PARA MOSTRAR";
		_getch();
		return;
	}
	else
	{
		cout << endl;
		cout << "Propietario" << endl;
		cout << "Nombre: " << tmp->getNombre() << endl;
		cout << "Apellido: " << tmp->getApellido() << endl;
		cout << "Cedula: " << tmp->getCedula() << endl;
		cout << "************************************";
	}
}