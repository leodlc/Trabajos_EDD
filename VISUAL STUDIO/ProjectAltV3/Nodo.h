#pragma once

#include <stdlib.h>
#include "Persona.h"
#include "Alumno.h"
#include "Profesor.h"
#pragma once
class Nodo
{
private:
	Persona persona;
	Alumno alumno;
	Profesor profesor;
	Nodo* siguiente;
	Nodo* anterior;

public:
	Nodo(Persona);
	Nodo(Alumno);
	Nodo(Profesor);
	Nodo();
	Persona getPersona();
	void setPersona(Persona persona);

	Profesor getProfesor();
	void setProfesor(Profesor profesor);

	Alumno getAlumno();
	void setAlumno(Alumno alumno);

	Nodo* getSiguiente();
	void setSiguiente(Nodo*);

	Nodo* getAnterior();
	void setAnterior(Nodo*);
};