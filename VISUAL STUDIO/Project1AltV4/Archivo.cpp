/***********************************************************************
 /** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
 * Module:  Asignatura.cpp
 * Author:  *Cristian Maranje
*Leonardo de la Cadena
*Johnny Loachamin
*Alvaro Zumba
 * Modified: Domingo, 21 de noviembre de 2021
 * Purpose: Division Clases Grupo
 ***********************************************************************/
#include "Archivo.h"


using namespace std;
Archivo::Archivo()
{
}

void Archivo::escribirArchivoAlumno(ListaCircularDoble lista, string nombreArch)
{
    ofstream archivo;
    archivo.open(nombreArch, ios::out | ios::app);

    if (archivo.fail())
    {
        cout << "ERROR!! EL ARCHIVO NO SE HA CREADO ";
        exit(1);
    }
    int cont = 0;
    lista.recorrer([&](Alumno alumno) {
        archivo << alumno.getNombre() << ","
            << alumno.getApellido() << ","
            << alumno.getID() << ","
            << alumno.getCedula() << ","
            << alumno.getContrasenaa() << ","
            << alumno.getCorreo() << ","
            << alumno.getUsuario() << ","
            /*<< alumno.getNota1() << ","
            << alumno.getNota2() << ","
            << alumno.getNota3() << ","*/
            << alumno.getNombreAsignatura() << ","
            << alumno.getNombreProfesor() << ","
            << alumno.getNotaAdquirida()
            << "\n";
        });
    archivo.close();
}

ListaCircularDoble Archivo::leerArchivoAlumno(string nombreArch)
{
    ifstream archivo(nombreArch);
    ListaCircularDoble lista;
    Alumno alumno;
    char ch;
    if (archivo.fail())
    {
        cout << "ERROR!! EL ARCHIVO NO SE HA CREADO ";
        exit(1);
    }
    else {
        string line;
        std::vector<std::string> values;
        while (getline(archivo, line)) {
            std::stringstream   linestream(line);
            std::string         value;

            while (getline(linestream, value, ','))
            {
                values.push_back(value);
            }
            alumno.setNombre(values.at(0));
            alumno.setApellido(values.at(1));
            alumno.setID(values.at(2));
            alumno.setCedula(std::stol(values.at(3)));
            alumno.setContrasena(values.at(4));
            alumno.setCorreo(values.at(5));
            alumno.setUsuario(values.at(6));
            /*alumno.setNota1(stof(values.at(6)));
            alumno.setNota2(stof(values.at(7)));
            alumno.setNota3(stof(values.at(8)));*/
            alumno.setNombreAsignatura(values.at(7));
            alumno.setNombreProfesor(values.at(8));
            alumno.setNotaAdquirida(stof(values.at(9)));
            lista.insertar(alumno);
            values.clear();
        }
    }
    archivo.close();
    return lista;
}



void Archivo::escribirArchivoProfesor(ListaCircularDoble lista, string nombreArch)
{
    ofstream archivo(nombreArch, std::ios_base::out | std::ios_base::app);
    if (archivo.fail())
    {
        cout << "ERROR!! EL ARCHIVO NO SE HA CREADO ";
        exit(1);
    }

    lista.recorrer([&](Profesor profesor) {
        archivo << profesor.getNombre() << ","
            << profesor.getApellido() << ","
            << profesor.getID() << ","
            << profesor.getCedula() << ","
            << profesor.getContrasenaa() << ","
            << profesor.getCorreo() << ","
            << profesor.getUsuario() << "\n";
            //<< profesor.getAsignaturaImpartida() <<
            


        });
    archivo.close();
}

ListaCircularDoble Archivo::leerArchivoProfesor(string nombreArch)
{
    ifstream archivo(nombreArch);
    ListaCircularDoble lista;
    Profesor profesor;
    char ch;
    if (archivo.fail())
    {
        cout << "ERROR!! EL ARCHIVO NO SE HA CREADO ";
        exit(1);
    }
    else {
        string line;
        std::vector<std::string> values;
        while (getline(archivo, line)) {
            std::stringstream   linestream(line);
            std::string         value;

            while (getline(linestream, value, ','))
            {
                values.push_back(value);
            }
            profesor.setNombre(values.at(0));
            profesor.setApellido(values.at(1));
            profesor.setID(values.at(2));
            profesor.setCedula(std::stol(values.at(3)));
            profesor.setContrasena(values.at(4));
            profesor.setCorreo(values.at(5));
            profesor.setUsuario(values.at(6));
            //profesor.setAsignaturaImpartida(values.at(7));
            lista.insertar(profesor);
            values.clear();
        }
    }
    archivo.close();
    return lista;
}

