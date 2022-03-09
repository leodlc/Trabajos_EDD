#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
template <typename tipoDato2>
class Oracion{
private:
	
	tipoDato2 cadena1;
	tipoDato2 cadena2;
public:
	Oracion(tipoDato2 _cadena1, tipoDato2 _cadena2) {
		cadena1 = _cadena1;
		cadena2 = _cadena2;
	}
	tipoDato2 setCadena1(string _cadena1) {

		cadena1 = _cadena1;
	}

	tipoDato2 setCadena2(string _cadena2) {

		cadena2 = _cadena2;

	}
	tipoDato2 getCadena1() {

		return cadena1;
	}

	tipoDato2 getCadena2() {

		return cadena2;
	}
	tipoDato2 concatenar();

};

template <typename tipoDato2>
tipoDato2 Oracion<tipoDato2>::concatenar() {
	return getCadena1() + " " + getCadena2;
}

