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
#include "Persona.h"
#include "Auto.h"
#include "Fecha.h"
#include "Tools.h"
#include "ListaPersona.h"
#include "Matricula.h"
#include "Placa.h"
#include <fstream>
#include <string>

using namespace std;

class ListaAuto {

private:
	Auto* primero;
	Auto* actual;

public:
	ListaAuto();
	void insertar(Auto*&, string, string, string, string, string, int, string);
	void insertarNuevo(Auto*&, string, string, string, string);
	Auto* localizar(Auto*, string);
	void imprimirUno(Auto*, Persona*, string);
	void matricular(Auto*&, string);
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
			string _marca = tmp.substr(0, tmp.find(","));
			tmp = tmp.substr(tmp.find(",") + 1, tmp.length());
			string _modelo = tmp.substr(0, tmp.find(","));
			tmp = tmp.substr(tmp.find(",") + 1, tmp.length());
			string _provincia= tmp.substr(0, tmp.find(","));
			tmp = tmp.substr(tmp.find(",") + 1, tmp.length());
			string _placa= tmp.substr(0, tmp.find(","));
			tmp = tmp.substr(tmp.find(",") + 1, tmp.length());
			int _estadoMat = stoi(tmp.substr(0, tmp.find(",")));
			string _fechaMat = tmp.substr(tmp.find(",") + 1, tmp.length());
			insertar(autos, _marca, _modelo,_cedula,_provincia, _placa, _estadoMat, _fechaMat);

		}
		myfile.close();
		out.close();
	}
}

void ListaAuto::insertar(Auto*& autos, string _marca, string _modelo, string _cedula, string _provincia, string _placa, int _estadoMat, string _fechaMat)
{
	Auto* nuevo = new Auto(_marca, _modelo, _cedula,_provincia, _placa, _estadoMat, _fechaMat);
	if (autos == NULL)
	{
		this->primero = nuevo;
		autos = nuevo;
	}
	else
	{
		this->actual->siguiente = nuevo;
	}

	this->actual = nuevo;
}
void ListaAuto::insertarNuevo(Auto*& autos, string _marca, string _modelo, string _cedula, string _provincia){
	
	Placa P; 
	string _placa = P.asignarPlaca(_provincia);
	int _estadoMat = 0;
	string _fechaMat = "000000";

	Auto* nuevo = new Auto(_marca, _modelo, _cedula,_provincia, _placa, _estadoMat, _fechaMat);
	if (autos == NULL)
	{
		autos = nuevo;
		this->primero = nuevo;
        fstream out("listaAuto.txt", fstream::app);
        if (out.is_open())
        {
            
			out << _cedula << "," << _marca << "," << _modelo <<","<<_provincia <<"," <<_placa <<"," << _estadoMat <<"," << _fechaMat << "\n";
        }
        out.close();
	}
	else
	{
		insertarNuevo(this->actual->siguiente, _marca, _modelo, _cedula, _provincia);
	}
	this->actual = nuevo;
}

void ListaAuto::imprimir(Auto* coches, Persona* personas)
{

	auto imprimirTodo = [=](Auto* autos, Persona* personas) -> void
	{
		Persona* pers = personas;
		Auto* tmp = coches;
		ListaPersona lst;
		if (actual == NULL)
		{
			cout << "\n\nNO HAY LISTA PARA MOSTRAR";
			_getch();
			return;
		}
		else
		{
			while (tmp != NULL)
			{
				cout << "************************************";
				cout << endl;
				cout << "Datos Vehiculo" << endl;
				cout << "Placa: " << tmp->getPlaca() << endl;
				cout << "Marca: " << tmp->getMarca() << endl;
				cout << "Modelo: " << tmp->getModelo() << endl;
				if(tmp->getMat().getEstado() == 1)
				{
					cout << "Estado Matricula: Matriculado" << endl;
					cout << "Fecha de Matricula: " << tmp->getMat().getFechaM() << endl;
				}
				else
				{
					cout << "Estado Matricula: No matriculado" << endl;
				}
				lst.imprimir(pers);
				cout << endl << endl;
				tmp = tmp->siguiente;
				pers = pers->getSiguiente();
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
	Auto* actual = autos;
	Persona* tmpPersonas = personas;
	Persona* propietario = NULL;
	Auto* tmp = NULL;
	Tools tool;

	while (actual != NULL || existe != true)
	{
		if (tool.compare(actual->getCedulaP(), _cedula) == 0)
		{
			propietario = tmpPersonas;
			tmp = actual;
			existe = true;
		}
		actual = actual->siguiente;
		tmpPersonas = tmpPersonas->getSiguiente();
	}

	if (existe == true)
	{
		cout << "************************************";
		cout << endl;
		cout << "Datos Vehiculo" << endl;
		cout << "Placa: " << tmp->getPlaca() << endl;
		cout << "Marca: " << tmp->getMarca() << endl;
		cout << "Modelo: " << tmp->getModelo() << endl;
		if (tmp->getMat().getEstado() == 1)
		{
			cout << "Estado Matricula: Matriculado" << endl;
			cout << "Fecha de Matricula: " << tmp->getMat().getFechaM() << endl;
		}
		else
		{
			cout << "Estado Matricula: No matriculado" << endl;
		}
		cout << endl;
		lst.imprimir(propietario);
		cout << endl;
		_getch();
	}
	else
	{
		cout << endl;
		cout << "Listo...";
		_getch();
	}
}

Auto* ListaAuto::localizar(Auto* autos, string _cedula)
{
	bool existe = false;
	ListaPersona lst;
	Auto* actual = autos;
	Auto* tmp = NULL;
	Tools tool;

	while (actual != NULL || existe != true)
	{
		if (tool.compare(actual->getCedulaP(), _cedula) == 0)
		{
			tmp = actual;
			existe = true;
		}
		actual = actual->siguiente;
	}
	return tmp;
}

void ListaAuto::matricular(Auto*& autos, string _cedula)
{
	Auto* aMatricular = localizar(autos, _cedula);

	if (aMatricular == NULL)
	{
		cout << "No hay registros..." << endl;
		system("pause");
	}
	else
	{
		char yn = 'x';
		cout << "Desea matricular el auto de placas " << aMatricular->getPlaca() << "? (y/n): ";
		cin >> yn;
		while (yn != 'y' && yn != 'n')
		{
			cout << "Opcion Invalida (y/n): ";
			cin >> yn;
		}

		if (yn == 'y')
		{
			if (aMatricular->mat.getEstado() == 1)
			{
				cout << "\nEste auto ya esta matriculado..." << endl;
			}
			else
			{
				string viejosDatos = aMatricular->cedulaPropietario + "," + aMatricular->marca + "," + aMatricular->modelo + "," + aMatricular->provincia + "," + aMatricular->placa + "," + to_string(aMatricular->mat.getEstado()) + "," + aMatricular->mat.getFechaM();
				Fecha fech;
				aMatricular->mat.setEstado(1);
				aMatricular->mat.setFechaM(fech.obtenerFecha());
				ofstream outFile;
				ifstream readFile;
				outFile.open("reemplazo.txt", ios_base::trunc);
				readFile.open("listaAuto.txt");
				string line;
				while (getline(readFile, line)) {
					if (line == viejosDatos) {
						outFile << aMatricular->cedulaPropietario << "," << aMatricular->marca << "," << aMatricular->modelo << "," << aMatricular->provincia << "," << aMatricular->placa << "," << aMatricular->mat.getEstado() << "," << aMatricular->mat.getFechaM() << "\n";
					}
					else {
						outFile << line << endl;
					}
				}
				outFile.close();
				readFile.close();
				remove("listaAuto.txt");
				rename("reemplazo.txt", "listaAuto.txt");
			}
		}
		else
		{
			system("cls");
			system("pause");
		}
	}
}

void ListaAuto::listarMatriculados(Auto* coches)
{
	auto imprimirTodo = [=](Auto* autos) -> void
	{
		Auto* tmp = coches;
		if (actual == NULL)
		{
			cout << "\n\nNO HAY LISTA PARA MOSTRAR";
			_getch();
			return;
		}
		else
		{
			while (tmp != NULL)
			{
				if (tmp->getMat().getEstado() == 1)
				{
					cout << "********************************************";
					cout << endl;
					cout << "Datos Vehiculo" << endl;
					cout << "Placa: " << tmp->getPlaca() << endl;
					cout << "Marca: " << tmp->getMarca() << endl;
					cout << "Modelo: " << tmp->getModelo() << endl;
					if (tmp->getMat().getEstado() == 1)
					{
						cout << "Estado Matricula: Matriculado" << endl;
						cout << "Fecha de Matricula: " << tmp->getMat().getFechaM() << endl;
					}
					else
					{
						cout << "Estado Matricula: No matriculado" << endl;
					}
					cout << "No. de cedula del propietario: " << tmp->getCedulaP();
					cout << endl << endl;
					cout << "************************************";
					tmp = tmp->siguiente;
				}
				else
				{
					cout << "";
					tmp = tmp->siguiente;
				}
			}
			cout << "\n\nEso es todo";
			_getch();
		}

	};

	imprimirTodo(coches);
}

void ListaAuto::listarNoMatriculados(Auto* coches)
{
	auto imprimirTodo = [=](Auto* autos) -> void
	{
		Auto* tmp = coches;
		if (actual == NULL)
		{
			cout << "\n\nNO HAY LISTA PARA MOSTRAR";
			_getch();
			return;
		}
		else
		{
			while (tmp != NULL)
			{
				if (tmp->getMat().getEstado() == 0)
				{
					cout << "********************************************";
					cout << endl;
					cout << "Datos Vehiculo" << endl;
					cout << "Placa: " << tmp->getPlaca() << endl;
					cout << "Marca: " << tmp->getMarca() << endl;
					cout << "Modelo: " << tmp->getModelo() << endl;
					if (tmp->getMat().getEstado() == 1)
					{
						cout << "Estado Matricula: Matriculado" << endl;
						cout << "Fecha de Matricula: " << tmp->getMat().getFechaM() << endl;
					}
					else
					{
						cout << "Estado Matricula: No matriculado" << endl;
					}
					cout << "No. de cedula del propietario: " << tmp->getCedulaP();
					cout << endl << endl;
					cout << "************************************";
					tmp = tmp->siguiente;
				}
				else
				{
					cout << "";
					tmp = tmp->siguiente;
				}
			}
			cout << "\n\nEso es todo";
			_getch();
		}

	};

	imprimirTodo(coches);
}
