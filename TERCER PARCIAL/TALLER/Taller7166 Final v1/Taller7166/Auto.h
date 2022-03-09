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
#include <iostream>
#include <string>
#include "Matricula.h"

using namespace std;


// placa, marca, modeo
class Auto {
private:

	string placa;
	string marca;
	string modelo;
	string cedulaPropietario;
	string provincia;
	Matricula mat;
	Auto* siguiente;

public:
	Auto(string, string, string, string, string, int, string);
	string getPlaca();
	string getMarca();
	string getModelo();
	string getProvincia();
	Auto* getSiguiente();
	string getCedulaP();
	Matricula getMat();
	void setPlaca(string);
	void setMarca(string);
	void setModelo(string);
	void setProvincia(string);
	void setSiguiente(Auto*);
	void setCedulaP(string);
	void setMat(Matricula);

	friend class ListaAuto;
};

Auto::Auto(string _marca, string _modelo, string _cedula,string _provincia, string _placa, int _estadoMat, string _fechaMat)
{
	this->marca = _marca;
	this->modelo = _modelo;
	this->cedulaPropietario = _cedula;
	this->provincia = _provincia;
	this->placa = _placa;
	this->mat.setEstado(_estadoMat);
	this->mat.setFechaM(_fechaMat);
	this->siguiente = NULL;
}
string Auto::getPlaca() {
	return this->placa;
}
string Auto::getMarca() {
	return this->marca;
}
string Auto::getModelo() {
	return this->modelo;
}
string Auto::getProvincia() {
	return this->provincia;
}
string Auto::getCedulaP() {
	return this->cedulaPropietario;
}
Matricula Auto::getMat()
{
	return this->mat;
}


void Auto::setPlaca(string _placa) {
	this->placa = _placa;
}
void Auto::setMarca(string _marca) {
	this->marca = _marca;
}
void Auto::setModelo(string _modelo) {
	this->modelo = _modelo;
}
void Auto::setProvincia(string _provincia) {
	this->provincia = _provincia;
}
void Auto::setCedulaP(string _cedulap) {
	this->cedulaPropietario = _cedulap;
}
Auto* Auto::getSiguiente()
{
	return this->siguiente;
}

void Auto::setSiguiente(Auto* _siguiente)
{
	this->siguiente = _siguiente;
}

void Auto::setMat(Matricula _mat)
{
	this->mat = _mat;
}
