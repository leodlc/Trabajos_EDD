/**************************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*TITULO: TALLER - MATRICULACION DE AUTOS
*AUTOR(ES): LUIS CUEVA, CHRISTIAN ANDRANGO
*FECHA: SABADO 26 DE FEBRERO DE 2022
*VERSION: 1
*ESTRUCTURA DE DATOS
*NRC: 7166
***************************************************************************/
#include "persona.h"

Persona::Persona(std::string cedula, std::string nombres, std::string apellidos) {
	cedula_ = cedula;
	nombres_ = nombres;
	apellidos_ = apellidos;
}

std::string Persona::cedula() {
	return cedula_;
}

void Persona::cedula(std::string cedula) {
	cedula_ = cedula;
}

std::string Persona::nombres() {
	return nombres_;
}

void Persona::nombres(std::string nombres) {
	nombres_ = nombres;
}

std::string Persona::apellidos() {
	return apellidos_;
}

void Persona::apellidos(std::string apellidos) {
	apellidos_ = apellidos;
}

void Persona::agregar_automovil(Automovil automovil) {
	automoviles_.insertar(automovil);
}

ListaEnlazada<Automovil> Persona::automoviles() {
	return automoviles_;
}
