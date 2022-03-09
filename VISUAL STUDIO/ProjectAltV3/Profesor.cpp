/***********************************************************************
 /** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
 * Modulo:  Profesor.cpp
 * Autores:  *Cristian Maranje
*Leonardo de la Cadena
*Johnny Loachamin
*Alvaro Zumba
  * Modified: Domingo, 21 de noviembre de 2021
 * Purpose: Division Clases Grupo
 ***********************************************************************/

#include "Profesor.h"
#include "ListaCircularDoble.h"
using namespace std;
Profesor::Profesor()
{
	this->asignaturaImpartida = "";
	this->notaAsignada = 0.0f;
}


//Profesor::~Profesor()
//{
//
//}

string Profesor::getAsignaturaImpartida(void)
{
   return asignaturaImpartida;
}


void Profesor::setAsignaturaImpartida(string newAsignaturaImpartida)
{
   asignaturaImpartida = newAsignaturaImpartida;
}


float Profesor::getNotaAsignada(void)
{
   return notaAsignada;
}


void Profesor::setNotaAsignada(float newNotaAsignada)
{
   notaAsignada = newNotaAsignada;
}


//float Profesor::ingresarNotaP1(void)
//{
//	/*float notaP1;
//	cout << "Ingrese la nota del primer parcial: " << endl;
//	cin >> notaP1;
//	while(!esFloat(to_string(notaP1)) && notaP1 >= 0 && notaP1 <=20){
//		cout << "El valor ingresado no es valido.\nIngrese la nota del primer parcial: ";
//		cin >> notaP1;
//	}
//	return notaP1;*/
//}
//
//
//float Profesor::ingresarNotaP2(void)
//{
//	/*float notaP2;
//	cout << "Ingrese la nota del segundo parcial" << endl;
//	cin >> notaP2;
//	while(!esFloat(to_string(notaP2)) && notaP2 >= 0 && notaP2 <=20){
//		cout << "El valor ingresado no es valido.\nIngrese la nota del primer parcial: ";
//		cin >> notaP2;
//	}
//	return notaP2;*/
//}
//
//
//float Profesor::ingresarNotaP3(void)
//{
//	/*float notaP3;
//	cout << "Ingrese la nota del tercer parcial" << endl;
//	cin >> notaP3;
//	while(!esFloat(to_string(notaP3)) && notaP3 >= 0 && notaP3 <=20){
//		cout << "El valor ingresado no es valido.\nIngrese la nota del primer parcial: ";
//		cin >> notaP3;
//	}
//	return notaP3;*/
//}
//float Profesor::calcularNotaFinal(float nota1, float nota2, float nota3) {
//	return (nota1 + nota2 + nota3) / 3;
//}
void Profesor::menuProfesor() {

	cout << "\n\t\tCUENTA PROFESOR\n\n";
	cout << " 1. INGRESAR NOTAS ALUMNO              " << endl;
	cout << " 2. REGRESAR                " << endl;
	cout << "\n INGRESE OPCION: ";

}
void Profesor::pantallaProfe(string usuarioProfesor) {
	//string opc, usuarioAlumno;
	//ListaCircularDoble listaAlumno;
	//ListaCircularDoble listaProfesor;
	//Archivo archivo;
	//int cont = 0;
	//Alumno alumno;
	//listaProfesor = archivo.leerArchivoProfesor("Profesores.txt" );
	//listaAlumno = archivo.leerArchivoAlumno("Alumnos.txt");
	//do {
	//	system("cls");
	//	menuProfesor();
	//	fflush(stdin);
	//	getline(cin >> ws, opc);
	//	opc = validarOpcMenu(opc, 2);
	//	switch (stoi(opc)) {
	//		case 1:
	//			cout << "Ingrese el usuario del alumno: ";
	//			getline(cin >> ws, usuarioAlumno);
	//			//listaAlumno.recorrer([&](Alumno alumno) {
	//			//	if(alumno.getUsuario() == usuarioAlumno){
	//			//		alumno.setNombreProfesor(usuarioProfesor);
	//			//		alumno.setNota1(ingresarNotaP1());
	//			//		alumno.setNota2(ingresarNotaP2());
	//			//		alumno.setNota3(ingresarNotaP3());
	//			//		alumno.setNotaAdquirida(calcularNotaFinal(alumno.getNota1(), alumno.getNota2(), alumno.getNota3()));
	//			//		listaProfesor.recorrer([&](Profesor profesor) {
	//			//			if (profesor.getUsuario() == usuarioProfesor) {
	//			//				alumno.setNombreAsignatura(profesor.getAsignaturaImpartida());
	//			//			}
	//			//		});
	//			//		++cont;
	//			//	}
	//			//});
	//			if(cont == 0){
	//				cout << "No se enconto el alumno." << endl;
	//			}
	//			else {
	//				archivo.escribirArchivoAlumno(listaAlumno, "Alumnos.txt");
	//			}
	//		break;
	//	}
	//	system("pause");
	//} while (stoi(opc) != 2);


}