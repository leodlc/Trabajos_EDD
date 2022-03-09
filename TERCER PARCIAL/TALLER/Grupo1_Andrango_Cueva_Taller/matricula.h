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
#include "persona.h"
#include "automovil.h"
#include "provincia.h"
#include "fecha.hpp"


class Matricula {
public:
	Matricula() = default;
	Matricula(Persona persona, Automovil automovil, Fecha fecha);

	Persona persona();
	void persona(Persona persona);

	Automovil automovil();
	void automovil(Automovil automovil);

	Fecha fecha();
	void fecha(Fecha fecha);

private:
	Persona persona_;
	Automovil automovil_;
	Fecha fecha_;
};
