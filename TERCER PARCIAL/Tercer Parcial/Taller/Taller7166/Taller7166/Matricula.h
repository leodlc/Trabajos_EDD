/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES: 
*
*Adrian Paez
*Juan Gallardo
*Leonardo de la Cadena
*TEMA: TALLER DE RECUPERACION - REGISTRO DE AUTOS
*FECHA DE CREACION : 26 DE FEBRERO DEL 2022
*FECHA DE MODIFICACION: 26 DE FEBRERO DEL 2022
* */
#pragma once
#include "Fecha.h"

class Matricula
{
private:
	bool estado;
	string fechaM;

public:
	Matricula() = default;
	//void matricular();
	bool getEstado();
	void setEstado(bool);
	string getFechaM();
	void setFechaM(string);

	friend class Auto;

};

bool Matricula::getEstado(){
	return this->estado;
}
void Matricula::setEstado(bool _estado){
	this->estado = _estado;
}
string Matricula::getFechaM(){
	return this->fechaM;
}
void Matricula::setFechaM(string _fechaM){
	this->fechaM = _fechaM;
}

