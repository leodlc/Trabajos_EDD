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

class Automovil
{
public:
	Automovil() = default;
	Automovil(int id, std::string placa, std::string marca, std::string modelo, std::string color);

	int id();
	void id(int id);

	std::string placa();
	void placa(std::string placa);

	std::string marca();
	void marca(std::string marca);

	std::string modelo();
	void modelo(std::string modelo);

	std::string color();
	void color(std::string color);

private:
	int id_ = 0;
	std::string placa_;
	std::string marca_;
	std::string modelo_;
	std::string color_;
};
