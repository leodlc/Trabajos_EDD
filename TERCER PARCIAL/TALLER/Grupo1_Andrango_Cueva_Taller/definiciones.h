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

#ifndef _MSC_VER
#define _getch(...) getch(__VA_ARGS__)
#endif

enum class Tecla : unsigned {
    Arriba = 72,
	Abajo = 80,
    Izquierda = 77,
    Derecha = 75,
    Escape = 27,
    Enter = 13,
};

inline constexpr unsigned operator+(Tecla const val) {
	return static_cast<unsigned>(val);
}

enum class TipoMensaje {
	Error,
	Correcto,
	Informativo
};

#define for_indexed(...) for_indexed_v(i, __VA_ARGS__)
#define for_indexed_v(v, ...) \
	if (std::size_t v = -1)   \
		for (__VA_ARGS__)     \
			if ((++v, true))

#define DOMINIO_EMAIL "espe.edu.ec"
#define ALUMNO_ID_PREFIJO "L00"
#define INTUIR_PROVINCIA_POR_CEDULA 1