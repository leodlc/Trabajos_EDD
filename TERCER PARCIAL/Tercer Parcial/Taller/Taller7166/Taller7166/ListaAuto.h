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
#include "Auto.h"
#include "Fecha.h"
#include "Tools.h"
#include "ListaPersona.h"
#include "Matricula.h"
#include "Placa.h"
#include <fstream>


using namespace std;

class ListaAuto {

private:
	Auto* primero;
	Auto* actual;

public:
	ListaAuto();
	void insertar(Auto*&, string, string, string, string, string);
	void insertarNuevo(Auto*&, string, string, string, string);
	bool buscar(Auto*, string);
	void imprimirUno(Auto*, Persona*, string);
	void matricular(Auto*, string);
	void inicializarListaA(Auto*&);
	void listarMatriculados(Auto*);
	void listarNoMatriculados(Auto*);
	void imprimir(Auto*, Persona*);
};

ListaAuto::ListaAuto()
{
	this->primero = NULL;
}

void ListaAuto::inicializarListaA(Auto*& autos){
	string line;
    fstream out;
    out.open("listaAuto.txt", fstream::in);
    ifstream myfile("listaAuto.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{

			string _cedula = line.substr(0, line.find(","));
			string tmp = line.substr(line.find(",") + 1, line.length());
			string _modelo = tmp.substr(0, tmp.find(","));
			tmp = tmp.substr(tmp.find(",") + 1, tmp.length());
			string _marca = tmp.substr(0, tmp.find(","));
			tmp = tmp.substr(tmp.find(",") + 1, tmp.length());
			string _provincia= tmp.substr(0, tmp.find(","));
			string _placa= tmp.substr(tmp.find(",") + 1, tmp.length());
			insertar(autos, _marca, _modelo,_cedula,_provincia, _placa);

		}
		myfile.close();
		out.close();
	}
}

void ListaAuto::insertar(Auto*& autos, string _marca, string _modelo, string _cedula, string _provincia,string _placa)
{
	Auto* nuevo = new Auto(_marca, _modelo, _cedula,_provincia, _placa);
	if (autos == NULL)
	{
		this->primero = nuevo;
		autos = nuevo;
	}
	else
	{
		autos->siguiente = nuevo;
	}

	autos = nuevo;
}
void ListaAuto::insertarNuevo(Auto*& autos, string _marca, string _modelo, string _cedula, string _provincia){
	
	Placa P; 
	string _placa = P.asignarPlaca(_provincia);


	Auto* nuevo = new Auto(_marca, _modelo, _cedula,_provincia, _placa);
	if (autos == NULL)
	{
		autos = nuevo;
		this->primero = nuevo;
        fstream out("listaAuto.txt", fstream::app);
        if (out.is_open())
        {
            
			out << _cedula << "," << _marca << "," << _modelo <<","<<_provincia << "\n";
        }
        out.close();
	}
	else
	{
		insertarNuevo(autos->siguiente, _marca, _modelo, _cedula, _provincia);
	}
	autos = nuevo;
}

void ListaAuto::imprimir(Auto* coches, Persona* personas)
{

	auto imprimirTodo = [=](Auto* autos, Persona* personas) -> void
	{
	Persona* pers = personas;
		Auto* actual = this->primero;
		ListaPersona lst;
		int cont = 1;
		if (actual == NULL)
		{
			cout << "\n\nNO HAY LISTA PARA MOSTRAR";
			_getch();
			return;
		}
		else
		{
			cout << endl << endl;
			while (actual != NULL)
			{
				cout << endl;
				cout << "Datos Vehiculo" << endl;
				cout << "Placa: " << actual->getPlaca() << endl;
				cout << "Marca: " << actual->getMarca() << endl;
				cout << "Modelo: " << actual->getModelo() << endl;
				cout << endl;
				cout << endl;
				cout << "Propietario: " << endl;
				cout << "Cedula: " << actual->getCedulaP();
				cout << endl;
				actual = actual->siguiente;
			}
			cout << "\n\nEso es todo";
			_getch();
		}

	};

	imprimirTodo(coches, personas);
	
}
	

void ListaAuto::imprimirUno(Auto* autos, Persona* personas, string _cedula)
{
	bool existe = false;
	ListaPersona lst;
	Auto* actual = this->primero;
	Auto* tmp = NULL;
	Tools tool;

	while (actual != NULL)
	{
		if (tool.compare(actual->getCedulaP(), _cedula) == 0) existe = true;
		tmp = actual;
		actual = actual->siguiente;
	}

	if (existe == true)
	{
		cout << endl;
		cout << "Datos Vehiculo" << endl;
		cout << "Placa: " << tmp->getPlaca() << endl;
		cout << "Marca: " << tmp->getMarca() << endl;
		cout << "Modelo: " << tmp->getModelo() << endl;
		cout << endl;
		cout << endl;
		cout << "Propietario: " << endl;
		lst.imprimirUno(personas, _cedula);
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "Listo...";
		_getch();
	}
}

void ListaAuto::matricular(Auto* autos, string _cedula)
{
	Auto* aMatricular = NULL;

	if (aMatricular == NULL)
	{
		cout << "No hay registros..." << endl;
		system("pause");
	}
	else
	{
		string yn;
		cout << "Desea matricular el auto de placas " << aMatricular->getPlaca() << "? (y/n): ";
		while (yn != "y" || yn != "n")
		{
			cout << "Opcion Invalida (y/n): ";
			cin >> yn;
		}

		if (yn == "y")
		{
			Fecha fech;
			aMatricular->mat.setEstado(true);
			aMatricular->mat.setFechaM(fech.obtenerFecha());
		}
		else
		{
			return;
		}
	}
}

void ListaAuto::listarMatriculados(Auto* autos)
{

}
