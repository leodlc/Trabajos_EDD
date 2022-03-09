#pragma once

#include "Nodo.h"
#include "Validaciones.h"
#include <iostream>
#include <functional>

class ListaCircularDoble
{
private:
	Nodo* primero;
	Nodo* ultimo;

public:
	ListaCircularDoble();
	void insertar(Persona persona);
	void insertar(Profesor profesor);
	void insertar(Alumno alumno);
	void recorrer(std::function<void(Persona)> callback);
	void recorrer(std::function<void(Profesor)> callback);
	void recorrer(std::function<void(Alumno)> callback);
	void revisarCorreoUsuario(Persona* persona);
	void revisarCorreoUsuario(Profesor* profesor);
	void revisarCorreoUsuario(Alumno* alomno);
	bool estaVacia();
	void eliminar(long int cedula);
};