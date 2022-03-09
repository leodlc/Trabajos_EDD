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
#include <conio.h>
#include <iostream>
#include <vector>
#include <Windows.h>
#include "Tools.h"
#include "Auto.h"
#include "ListaAuto.h"
#include "Persona.h"
#include "ListaPersona.h"
#include <string>

/**
* @file menu.h
* @author Adrian Paez			
* @author Leonardo de la Cadena
* @version 1.0
*/

#define KEY_UP 72
#define KEY_DOWN 80
#define ENTER 13

using namespace std;

class MyMenu
{

private:
	Auto* lstAuto = NULL;
	Persona* lstPersona = NULL;
	bool running = false;

public:

	/**
	* @brief automatization of capture option in a menu controlled with directional keys
	* @param string, vector<string>, int
	* @return int
	*/
	int showCaptureOp(string, vector<std::string>, int);

	/**
	* @brief principal menu decision routine
	* @param
	* @return void
	*/
	void principalMenu();

	/**
	* @param show authentication menu
	* @param
	* @return void
	*/

};

int MyMenu::showCaptureOp(string name, vector<std::string> options, int count)
{
	Tools tool;
	int option = 1;
	int key;

	bool repeat = true;

	do {

		system("cls");

		cout << "\t" << name << endl;
		tool.gotoxy(5, 1 + option);
		cout << "=>";

		for (int i = 1; i <= count; i++)
		{
			tool.gotoxy(12, 1 + i);  cout << i << ". " << options[i - 1];
		}

		do {

			key = _getch();

		} while (key != KEY_UP && key != KEY_DOWN && key != ENTER);

		switch (key)
		{
		case KEY_UP:
			option--;
			if (option == 0) option = count;
			break;
		case KEY_DOWN:
			option++;
			if (option > count) option = 1;
			break;
		case ENTER:
			repeat = false;
			break;
		}

	} while (repeat);

	return option;
}

void MyMenu::principalMenu()
{

	ListaPersona personas;
	ListaAuto autos;
	cout << "\n " << endl;
	cout << "\n " << endl;
	vector<std::string> options = { "Registro de persona", "Registro de auto", "Registro de matricula", "Imprimir persona", "Imprimir auto", "Listar autos matriculados", "Listar autos no matriculados", "Listar personas con sus autos", "Salir" };
	vector<std::string> yn = { "Si", "No" };
	bool repeat = true;
	int option;
	string nombre, apellido, cedula, marca, modelo, provincia;
	int op;
	Tools tool;
	personas.inicializarListaP(this->lstPersona);
	autos.inicializarListaA(this->lstAuto);
	do
	{
		system("cls");

		cout << "\n " << endl;
		cout << "\n " << endl;

		option = showCaptureOp("\n\t    MATRICULACION...", options, 9);
		switch (option)
		{
		case 1:
			system("cls");
			nombre = tool.validate_string("\nIngrese el nombre: ");
			apellido = tool.validate_string("\nIngrese el apellido: ");
			cedula = tool.validate_string_of_numbers("\nIngrese el No. de cedula: ");
			while (tool.validate_id(cedula)) cedula = tool.validate_string_of_numbers("\nIngrese un No. de cedula valido: ");
			personas.insertarNuevo(this->lstPersona, nombre, apellido, cedula);
			
			break;
		case 2:
			system("cls");
			op = showCaptureOp("El propietario fue previamente registrado?:", yn, 2);
			if (op == 1)
			{
				cedula = tool.validate_string_of_numbers("\nIngrese el No. de cedula del propietario: ");
				while (tool.validate_id(cedula)) cedula = tool.validate_string_of_numbers("\nIngrese un No. de cedula valido: ");
				if (personas.buscar(this->lstPersona, cedula) == true)
				{
					cout << "Ahora puede registrar el auto: " << endl;
					marca = tool.validate_string("\nIngrese la marca del auto: ");
					cout << "\nIngrese el modelo del auto: ";
					cin >> modelo;
					provincia = tool.validate_string("\nIngrese la provincia: ");
					autos.insertarNuevo(this->lstAuto, marca, modelo, cedula, provincia);
				}
				else
				{
					cout << "El propietario no esta registrado" << endl;
					_getch();
				}
			}
			else
			{
				cout << "Para poder registrar un auto debe primero registrar a su propietario..." << endl;
				op = showCaptureOp("Desea registrar al propietario del auto?", yn, 2);
				if (op == 1)
				{
					system("cls");
					nombre = tool.validate_string("\nIngrese el nombre ");
					apellido = tool.validate_string("\nIngrese el apellido: ");
					cedula = tool.validate_string_of_numbers("\nIngrese el No. de cedula: ");
					while (tool.validate_id(cedula)) cedula = tool.validate_string_of_numbers("\nIngrese un No. de cedula valido: ");
					personas.insertarNuevo(this->lstPersona, nombre, apellido, cedula);
					cout << endl;
					cout << "Ahora puede registrar el auto: " << endl;
					marca = tool.validate_string("\nIngrese la marca del auto: ");
					cout << "\nIngrese el modelo del auto: ";
					cin >> modelo;
					provincia = tool.validate_string("\nIngrese la provincia: ");
					autos.insertarNuevo(this->lstAuto, marca, modelo, cedula, provincia);
				}
				else
				{
					cout << endl;
					cout << endl;
					system("\tpause");
				}
			}			
			break;
		case 3:
			system("cls");
			cedula = tool.validate_string_of_numbers("\nIngrese el No. de cedula del propietario: ");
			while (tool.validate_id(cedula)) cedula = tool.validate_string_of_numbers("\nIngrese un No. de cedula valido: ");
			autos.matricular(this->lstAuto, cedula);
			_getch();
			break;
		case 4:
			system("cls");
			cedula = tool.validate_string_of_numbers("\nIngrese el No. de cedula de la persona: ");
			while (tool.validate_id(cedula)) cedula = tool.validate_string_of_numbers("\nIngrese un No. de cedula valido: ");
			personas.imprimirUno(this->lstPersona, cedula);
			break;
		case 5:
			system("cls");
			op = showCaptureOp("El auto esta registrado a nombre de un propietario?", yn, 2);
			if (op == 1)
			{
				system("cls");
				cedula = tool.validate_string_of_numbers("\nIngrese el No. de cedula del propietario: ");
				while (tool.validate_id(cedula)) cedula = tool.validate_string_of_numbers("\nIngrese un No. de cedula valido: ");
				if (personas.buscar(this->lstPersona, cedula) == true) autos.imprimirUno(this->lstAuto, this->lstPersona ,cedula);
				else
				{
					cout << "No hay registros!!" << endl;
					cout << endl;
					system("pause");
				}
			}
			else
			{
				system("cls");
				cout << "Para poder registrar un auto debe primero registrar a su propietario..." << endl;
				op = showCaptureOp("El auto esta registrado a nombre de un propietario?", yn, 2);
				if (op == 1)
				{
					system("cls");
					nombre = tool.validate_string("\nIngrese el nombre ");
					apellido = tool.validate_string("\nIngrese el apellido: ");
					cedula = tool.validate_string_of_numbers("\nIngrese el No. de cedula: ");
					while (tool.validate_id(cedula)) cedula = tool.validate_string_of_numbers("\nIngrese un No. de cedula valido: ");
					personas.insertarNuevo(this->lstPersona, nombre, apellido, cedula);

					cout << "Ahora puede registrar el auto: " << endl;
					marca = tool.validate_string("\nIngrese la marca del auto: ");
					cout << "\nIngrese el modelo del auto: ";
					cin >> modelo;
					provincia = tool.validate_string("\nIngrese la provincia: ");
					autos.insertarNuevo(this->lstAuto, marca, modelo, cedula, provincia);
				}
				else
				{
					return;
				}
			}
			break;
		case 6:
			system("cls");
			//listar autos matriculados
			break;
		case 7:
			system("cls");
			//listar autos no matriculados
			break;
		case 8:
			system("cls");
			autos.imprimir(this->lstAuto, this->lstPersona);
			//listar personas con sus autos
			break;
		case 9:
			system("cls");
			cout << "\nSaliendo... " << endl;
			Sleep(100);
			//showAuthMenu();
			repeat = false;
			break;

		}

	} while (repeat);

	exit(0);

}

