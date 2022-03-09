/**************************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*TITULO: TALLER - MATRICULACION DE AUTOS
*AUTOR(ES): LUIS CUEVA, CHRISTIAN ANDRANGO
*FECHA: SABADO 26 DE FEBRERO DE 2022
*VERSION: 1
*ESTRUCTURA DE DATOS
*NRC: 7166
***************************************************************************/
#include "automovil.h"

Automovil::Automovil(int id, std::string placa, std::string marca, std::string modelo, std::string color) {
	id_ = id;
	placa_ = placa;
	marca_ = marca;
	modelo_ = modelo;
	color_ = color;
}

int Automovil::id()
{
    return id_;
}

void Automovil::id(int id)
{
	id_ = id;
}

std::string Automovil::placa()
{
	return placa_;
}

void Automovil::placa(std::string placa)
{
	placa_ = placa;
}

std::string Automovil::marca() {
	return marca_;
}

void Automovil::marca(std::string marca) {
	marca_ = marca;
}

std::string Automovil::modelo() {
	return modelo_;
}

void Automovil::modelo(std::string modelo) {
	modelo_ = modelo;
}

std::string Automovil::color() {
	return color_;
}

void Automovil::color(std::string color) {
	color_ = color;
}
