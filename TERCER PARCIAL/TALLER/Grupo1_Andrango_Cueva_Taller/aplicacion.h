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
#include "automovil.h"
#include "servicio_personas.h"
#include "servicio_automoviles.h"
#include "servicio_matriculas.h"

class Aplicacion {
public:
	Aplicacion() = default;
	void iniciar();
	void menu_agregar_persona();
	void menu_agregar_automovil();
	void menu_asignar_automovil();
	void menu_registro_matricula();
	void menu_imprimir_personas();
	void menu_imprimir_automoviles();
	void menu_imprimir_automoviles_personas();

private:
	ServicioPersonas servicio_personas_;
	ServicioAutomoviles servicio_automoviles_;
	ServicioMatriculas servicio_matriculas_;
};
