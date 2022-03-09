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
#include "automovil.h"
#include <optional>

class ServicioAutomoviles {
public:
	ServicioAutomoviles();
	ListaDobleEnlazada<Automovil> obtener_todo();
	std::optional<Automovil> obtener_por_placa(std::string placa);
	std::optional<Automovil> obtener_por_id(int id);
	void crear(Automovil automovil);
	void actualizar(int id, Automovil automovil);
	bool es_duenio(std::string cedula, int id);
	int ultimo_id();

private:
};
