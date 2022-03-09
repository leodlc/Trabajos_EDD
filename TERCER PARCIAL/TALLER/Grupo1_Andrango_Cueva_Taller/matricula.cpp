/**************************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*TITULO: TALLER - MATRICULACION DE AUTOS
*AUTOR(ES): LUIS CUEVA, CHRISTIAN ANDRANGO
*FECHA: SABADO 26 DE FEBRERO DE 2022
*VERSION: 1
*ESTRUCTURA DE DATOS
*NRC: 7166
***************************************************************************/
#include "matricula.h"

Matricula::Matricula(Persona persona, Automovil automovil, Fecha fecha) {
	persona_ = persona;
	automovil_ = automovil;
	fecha_ = fecha;
}

Persona Matricula::persona() {
	return persona_;
}

void Matricula::persona(Persona persona) {
	persona_ = persona;
}

Automovil Matricula::automovil() {
	return automovil_;
}

void Matricula::automovil(Automovil automovil) {
	automovil_ = automovil;
}

Fecha Matricula::fecha() {
	return fecha_;
}

void Matricula::fecha(Fecha fecha) {
	fecha_ = fecha;
}
