/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTOR: Leonardo de la Cadena
*TEMA: Coreccion Prueba Conjunta Parcial 1
*FECHA DE CREACION : 01 DE DICIEMBRE DEL 2021
* *FECHA DE MODIFICACION : 02 DE DICIEMBRE DEL 2021

* */
#pragma once
#include "Nodo.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
class Fecha
{
public:
	Fecha(int _dia, int _mes, int _anio, int _diaNac, int _mesNac, int _anioNac);
	Fecha();
	~Fecha();
	int getDiaAct(void);
	void setDiaAct(int _diaAct);
	int getMesAct(void);
	void setMesAct(int _mesAct);
	int getAnioAct(void);
	void setAnioAct(int _anioAct);
	int getDiaNac(void);
	void setDiaNac(int _diaNac);
	int getMesNac(void);
	void setMesNac(int _mesNac);
	int getAnioNac(void);
	void setAnioNac(int _anioNac);
	int calcularEdad(int _diaAct, int _mesAct, int _anioAct, int _diaNac, int _mesNac, int _anioNac);
	//int fechaUnida(int _diaAct, int _mesAct, int _anioAct);
protected:
private:
	int diaAct;
	int mesAct;
	int anioAct;
	int diaNac, mesNac, anioNac;


};

