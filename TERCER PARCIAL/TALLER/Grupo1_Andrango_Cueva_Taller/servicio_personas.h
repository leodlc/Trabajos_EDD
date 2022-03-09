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
#include "lista_doble_enlazada.h"
#include "persona.h"
#include <optional>
#include <fstream>
#include "servicio_automoviles.h"

class ServicioPersonas {
public:
	ServicioPersonas();
	ListaDobleEnlazada<Persona> obtener_todo();
	std::optional<Persona> obtener(std::string cedula);
	void crear(Persona persona);
	ListaEnlazada<Automovil> obtener_automoviles(std::string cedula);
	void agregar_automovil(std::string cedula, Automovil automovil);

private:
	ServicioAutomoviles servicio_automoviles_;
};
