/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTOR: Leonardo de la Cadena
*TEMA: Coreccion Prueba Conjunta Parcial 1
*FECHA DE CREACION : 06 DE DICIEMBRE DEL 2021
* *FECHA DE MODIFICACION : 07 DE DICIEMBRE DEL 2021

* */
#include "Fecha.h"
#include "Validar.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
Fecha::Fecha() {

}
Fecha::Fecha(int _diaAct, int _mesAct, int _anioAct, int _diaNac, int _mesNac, int _anioNac) {
	diaAct = _diaAct;
	mesAct = _mesAct;
	anioAct = _anioAct;
	diaNac = _diaNac;
	mesNac = _mesNac;
	anioNac = _anioNac;

}


Fecha::~Fecha()
{

}


int Fecha::getDiaAct(void)
{
	return diaAct;
}


void Fecha::setDiaAct(int _dia)
{
	diaAct = _dia;
}


int Fecha::getMesAct(void)
{
	return mesAct;
}


void Fecha::setMesAct(int _mes)
{
	mesAct = _mes;
}


int Fecha::getAnioAct(void)
{
	return anioAct;
}


void Fecha::setAnioAct(int _anio)
{
	anioAct = _anio;
}
//--------------------------
int Fecha::getDiaNac(void)
{
	return diaNac;
}


void Fecha::setDiaNac(int _diaNac)
{
	diaAct = _diaNac;
}


int Fecha::getMesNac(void)
{
	return mesNac;
}


void Fecha::setMesNac(int _mesNac)
{
	mesAct = _mesNac;
}


int Fecha::getAnioNac(void)
{
	return anioNac;
}


void Fecha::setAnioNac(int _anioNac)
{
	anioAct = _anioNac;
}


int Fecha::calcularEdad(int _diaAct, int _mesAct, int _anioAct, int _diaNac, int _mesNac, int _anioNac)
{
	int edad,mesFin,diaFin;
	if (_mesNac < _mesAct) {
		edad = _anioAct - _anioNac;

	}
	else if (_mesNac == _mesAct) {
		if (_diaNac <= _diaAct) {
			edad = _anioAct - _anioNac;

		}
		else {
			edad = (_anioAct - _anioNac) - 1;
		}
	}
	else if (_mesNac > _mesAct) {
		edad = (_anioAct - _anioNac) - 1;
	}
	cout << "Edad: " << edad<<endl;

	



	return edad;
}
