#pragma once

#include <iostream>
#include <string>
//#include "Matricula.h"

using namespace std;


// placa, marca, modeo
class Auto {
private:

	string placa;
	string marca;
	string modelo;
	string cedulaPropietario;
	string provincia;
	//Matricula mat;
	Auto* siguiente;

public:
	Auto();
	Auto(string, string, string, string, string);
	string getPlaca();
	string getMarca();
	string getModelo();
	string getProvincia();
	Auto* getSiguiente();
	string getCedulaP();
	void setPlaca(string);
	void setMarca(string);
	void setModelo(string);
	void setProvincia(string);
	void setSiguiente(Auto*);
	void setCedulaP(string);


	friend class ListaAuto;
};

Auto::Auto(string _marca, string _modelo, string _cedula, string _provincia, string _placa)
{
	this->placa = _placa;
	this->marca = _marca;
	this->modelo = _modelo;
	this->cedulaPropietario = _cedula;
	this->provincia = _provincia;
	this->siguiente = NULL;
	//this->mat.setEstado(false);
}
Auto::Auto() {

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
