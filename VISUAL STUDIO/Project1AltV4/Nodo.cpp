#include "Nodo.h"

Nodo::Nodo(Persona persona) {
    this->persona = persona;
}

Nodo::Nodo(Alumno alumno) {
    this->alumno = alumno;
}

Nodo::Nodo(Profesor profesor) {
    this->profesor = profesor;
}

Nodo::Nodo() {
    this->persona = Persona();
}

Nodo* Nodo::getAnterior() {
    return anterior;
}

void Nodo::setAnterior(Nodo* nodo) {
    this->anterior = nodo;
}

Nodo* Nodo::getSiguiente() {
    return siguiente;
}

void Nodo::setSiguiente(Nodo* nodo) {
    this->siguiente = nodo;
}

Persona Nodo::getPersona() {
    return persona;
}

void Nodo::setPersona(Persona persona) {
    this->persona = persona;
}

Profesor Nodo::getProfesor() {
    return profesor;
}

void Nodo::setProfesor(Profesor profesor) {
    this->profesor = profesor;
}

Alumno Nodo::getAlumno() {
    return alumno;
}

void Nodo::setAlumno(Alumno alumno) {
    this->alumno = alumno;
}
