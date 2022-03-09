/***********************************************************************
 /** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
 * Module:  Alumno.cpp
 * Author:  *Cristian Maranje
*Leonardo de la Cadena
*Johnny Loachamin
*Alvaro Zumba
  * Modified: Domingo, 21 de noviembre de 2021
 * Purpose: Division Clases Grupo
 ***********************************************************************/

#include "Alumno.h"
#include "Asignatura.h"
#include "ListaCircularDoble.h"
#include "Archivo.h"
using namespace std;

Alumno::Alumno()
{
	this->notaAdquirida = 0.0f;
	this->nota1 = 0.0f;
	this->nota2 = 0.0f;
	this->nota3 = 0.0f;
	this->nombreAsignatura = "";
	this->nombreProfesor = "";
}
float Alumno::getNota1(void)
{
	return nota1;
}
void Alumno::setNota1(float newNota1)
{
	nota1 = newNota1;
}

float Alumno::getNota2(void)
{
	return nota2;
}
void Alumno::setNota2(float newNota2)
{
	nota2 = newNota2;
}

float Alumno::getNota3(void)
{
	return nota3;
}
void Alumno::setNota3(float newNota3)
{
	nota3 = newNota3;
}
float Alumno::getNotaAdquirida(void)
{
   return notaAdquirida;
}

string Alumno::getNombreAsignatura(){
	return nombreAsignatura;
}
void Alumno::setNombreAsignatura(string newNombreAsignatura){
	this->nombreAsignatura = newNombreAsignatura;
}
string Alumno::getNombreProfesor(){
	return nombreProfesor;
}
void Alumno::setNombreProfesor(string newNombreProfesor){
	this->nombreProfesor = newNombreProfesor;
}
   


void Alumno::setNotaAdquirida(float newNotaAdquirida)
{
   notaAdquirida = newNotaAdquirida;
}

void Alumno::verNotas(string usuarioAlumno)
{
 //  ListaCircularDoble listaAlumno;
 //  Archivo archivo;
 //  Alumno alumno;
 //  listaAlumno = archivo.leerArchivoAlumno("Alumnos.txt");
 //  listaAlumno.recorrer([&](Alumno alumno) {
	//   if (alumno.getUsuario() == usuarioAlumno) {
	//	   cout << "Nombre: " << alumno.getNombre() << endl;
	//	   cout << "Apellido: " << alumno.getApellido() << endl;
	//	   cout << "ID: " << alumno.getID() << endl;
	//	   cout << "Correo: " << alumno.getCorreo() << endl;
	//	   cout << "Materia: " << alumno.getNombreAsignatura() << endl;
	//	   cout << "Profesor: " << alumno.getNombreProfesor() << endl;
	//	   cout << "Notas: \nNota 1: " << alumno.getNota1() << endl;
	//	   cout << "Nota 2: " << alumno.getNota2() << endl;
	//	   cout << "Nota 3: " << alumno.getNota3() << endl;
	//	   cout << "Nota final: " << alumno.getNotaAdquirida() << endl;
	//   }
					
	//});
}