#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

//dia hora y mes
class Fecha
{
private:
public:
	string obtenerFecha();
	
};

string Fecha::obtenerFecha()
{
	time_t tiempoahora;
	time(&tiempoahora);

	struct tm* mitiempo = localtime(&tiempoahora);
	string dia = to_string(mitiempo->tm_mday);
	string mes = to_string(mitiempo->tm_mon);
	string anio = to_string(mitiempo->tm_year + 1900);
	string fecha = dia + "/" + mes + "/" + anio;

	return fecha;

}

