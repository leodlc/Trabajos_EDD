/**************************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*TITULO: TALLER - MATRICULACION DE AUTOS
*AUTOR(ES): LUIS CUEVA, CHRISTIAN ANDRANGO
*FECHA: SABADO 26 DE FEBRERO DE 2022
*VERSION: 1
*ESTRUCTURA DE DATOS
*NRC: 7166
***************************************************************************/
#pragma once
#include <string>
#include "lista_enlazada.h"
#include "automovil.h"

class Persona
{
public:
	Persona() = default;
	Persona(std::string cedula, std::string nombres, std::string apellidos);

	std::string cedula();
	void cedula(std::string cedula);

	std::string nombres();
	void nombres(std::string nombres);

	std::string apellidos();
	void apellidos(std::string apellidos);

	void agregar_automovil(Automovil automovil);
	ListaEnlazada<Automovil> automoviles();

private: 
	std::string cedula_;
	std::string nombres_;
	std::string apellidos_;
	ListaEnlazada<Automovil> automoviles_;
};