#include "Administrador.h"
#include "Login.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Profesor.h"
#include "Archivo.h"

using namespace std;
/***********************************************************************
 * Module:  Administrador.cpp
 * Author:  AsrockLeo
 * Modified: lunes, 29 de noviembre de 2021 21:04:27
 * Purpose: Implementation of the class Administrador
 ***********************************************************************/



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
	this->contrasena = "";
	this->usuario = "";
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

Alumno Administrador::registrarAlumno(void)
{

	Alumno nuevoAlumno;
	string dato;
	long int CI = 0;
	std::cout << "Ingrese el nombre: " << endl;
	fflush(stdin);
	getline(cin >> ws, dato);
	while (!esCadena(dato)) {
		cout << "El nombre no es valido. \nIngrese el nombre: ";
		fflush(stdin);
		getline(cin >> ws, dato);
	}
	nuevoAlumno.setNombre(dato);

	std::cout << "Ingrese el Apellido: " << endl;
	fflush(stdin);
	getline(cin >> ws, dato);
	nuevoAlumno.setApellido(dato);

	fflush(stdin);
	std::cout << "Ingrese el ID: " << endl;
	fflush(stdin);
	getline(cin >> ws, dato);
	nuevoAlumno.setID(dato);

	std::cout << "Ingrese la cedula: " << endl;
	fflush(stdin);
	cin >> CI;
	CI = validarCedula(CI);
	nuevoAlumno.setCedula(CI);

	cout << "Ingrese la contrase�a" << endl;
	fflush(stdin);
	getline(cin >> ws, dato);
	nuevoAlumno.setContrasena(dato);

	nuevoAlumno.generarCorreoUsuario(0);
	std::cout << "El correo es: " << nuevoAlumno.getCorreo() << endl;
	std::cout << "El usuario es: " << nuevoAlumno.getUsuario() << endl;



	return nuevoAlumno;
}

////////////////////////////////////////////////////////////////////////
// Name:       Administrador::registroProfesor()
// Purpose:    Implementation of Administrador::registroProfesor()
// Return:     void
////////////////////////////////////////////////////////////////////////

Profesor Administrador::registroProfesor(void)
{
	Profesor nuevoProfesor;
	string dato;
	long int CI = 0;
	std::cout << "Ingrese el nombre: " << endl;
	fflush(stdin);
	getline(cin >> ws, dato);
	while (!esCadena(dato)) {
		cout << "El nombre no es valido. \nIngrese el nombre: ";
		fflush(stdin);
		getline(cin >> ws, dato);
	}
	nuevoProfesor.setNombre(dato);

	std::cout << "Ingrese el Apellido: " << endl;
	fflush(stdin);
	getline(cin >> ws, dato);
	nuevoProfesor.setApellido(dato);

	fflush(stdin);
	std::cout << "Ingrese el ID: " << endl;
	fflush(stdin);
	getline(cin >> ws, dato);
	nuevoProfesor.setID(dato);

	std::cout << "Ingrese la cedula: " << endl;
	fflush(stdin);
	cin >> CI;
	CI = validarCedula(CI);
	nuevoProfesor.setCedula(CI);

	cout << "Ingrese la contrase�a: " << endl;
	fflush(stdin);
	getline(cin >> ws, dato);
	nuevoProfesor.setContrasena(dato);

	nuevoProfesor.generarCorreoUsuario(0);

	/*cout << "Ingrese la materia: " << endl;
	fflush(stdin);
	getline(cin >> ws, dato);
	nuevoProfesor.setAsignaturaImpartida(dato);*/

	std::cout << "El correo es: " << nuevoProfesor.getCorreo() << endl;
	std::cout << "El usuario es: " << nuevoProfesor.getUsuario() << endl;
	return nuevoProfesor;
}



void menuAdmin() {

	cout << "\n\t\tCUENTA ADMIN\n\n";
	cout << " 1. REGISTRAR ALUMNO              " << endl;
	cout << " 2. REGISTRAR PROFESOR                " << endl;
	cout << " 3. REGRESAR               " << endl;
	cout << " 4. SALIR                    " << endl;


	cout << "\n INGRESE OPCION: ";

}
void Administrador::pantallaAdmin(void) {
	string opc;
	int cont = 0;
	ListaCircularDoble listaProfesor;
	ListaCircularDoble listaAlumno;
	Persona newPersona;
	Archivo archivo;

	do {
		system("cls");
		menuAdmin();
		getline(cin >> ws, opc);
		opc = validarOpcMenu(opc, 4);

		switch (stoi(opc)) {
		case 1:
			newPersona = registrarAlumno();
			listaAlumno.revisarCorreoUsuario(&newPersona);
			listaAlumno.insertar(newPersona);
			if (!listaAlumno.estaVacia()) {
				archivo.escribirArchivoAlumno(listaAlumno, "Alumnos.txt");
			}
			break;
		case 2:
			newPersona = registroProfesor();
			listaProfesor.revisarCorreoUsuario(&newPersona);
			listaProfesor.insertar(newPersona);
			if (!listaProfesor.estaVacia()) {
				archivo.escribirArchivoProfesor(listaProfesor, "Profesores.txt");
			}
			break;
		case 5:

			exit(1);
			break;
		}
		system("pause");
	} while (stoi(opc) != 3);


}


