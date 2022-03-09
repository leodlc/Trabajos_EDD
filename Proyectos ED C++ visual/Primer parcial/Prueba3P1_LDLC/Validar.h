/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTOR: Leonardo de la Cadena
*TEMA: Coreccion Prueba Conjunta Parcial 1
*FECHA DE CREACION : 01 DE DICIEMBRE DEL 2021
* *FECHA DE MODIFICACION : 02 DE DICIEMBRE DEL 2021

* */
#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>


//regresa boleano true si el numero de dias es correcto respecto al mes
inline bool validarLosDias(int dia, int mes,int anio)
{
	if (dia <= 0)
	{
		
		return false;
		
	}
	else if ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11))
	{
		if (dia > 30)
		{
			
			cout << "No existe mas de 30 dias en ese mes." << endl;
			return false;
		}
		else
		{
			return true;
		}
	}
	else if ((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12))
	{
		if (dia > 31)
		{
			cout << "No existe mas de 31 dias en el mes." << endl;
			return false;
		}
		else
		{
			return true;
		}
	}
	else if ((mes == 2))
	{
		if (dia > 28)
		{
			cout << "no existe esa fecha en el mes de febrero." << endl;
			return false;
		}
		else
		{
			return true;
		}
	}
	else if ((mes == false)&&(dia==false)&&(anio==false)) {
		cout << "Debe ingresar un numero" << endl;
	}
	return false;
}
inline bool validarDato(int dato) {
	if (dato == false) {
		while (dato == false) {
			cout << "Se requiere ingresar un numero" << endl;
			cout << "El programa se va a reiniciar" << endl;
			break;
			
			
			
		}
		exit(0);
	}
	else { return true; }
	return false;
}
