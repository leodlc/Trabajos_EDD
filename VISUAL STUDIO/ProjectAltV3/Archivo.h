
#include"ListaCircularDoble.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Alumno.h"
#include "Profesor.h"
using namespace std;
#pragma once


class Archivo {

public:
    Archivo();
    void escribirArchivoAlumno(ListaCircularDoble lista, string nombreArch);
    ListaCircularDoble leerArchivoAlumno( string nombreArch);
    void escribirArchivoProfesor(ListaCircularDoble lista, string nombreArch);
    ListaCircularDoble leerArchivoProfesor(string nombreArch);

};