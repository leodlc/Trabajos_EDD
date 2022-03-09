/**************************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*TITULO: TALLER - MATRICULACION DE AUTOS
*AUTOR(ES): LUIS CUEVA, CHRISTIAN ANDRANGO
*FECHA: SABADO 26 DE FEBRERO DE 2022
*VERSION: 1
*ESTRUCTURA DE DATOS
*NRC: 7166
***************************************************************************/
#include "servicio_automoviles.h"
#include <fast-csv-parser/csv.h>
#include "utilidades.h"

ServicioAutomoviles::ServicioAutomoviles() {
	Utilidades::crear_archivo("automoviles.txt");
}

ListaDobleEnlazada<Automovil> ServicioAutomoviles::obtener_todo() {
	ListaDobleEnlazada<Automovil> automoviles;
	
	io::CSVReader<5, io::trim_chars<' '>, io::double_quote_escape<',', '"'>> in("automoviles.txt");

	int id = 0;
	std::string placa;
	std::string marca;
	std::string modelo;
	std::string color;

	while (in.read_row(id, placa, marca, modelo, color)) {
		automoviles.insertar(Automovil(
			id,
			placa,
			marca,
			modelo,
			color
		));
	}

	return automoviles;
}

std::optional<Automovil> ServicioAutomoviles::obtener_por_placa(std::string placa) {
	ListaDobleEnlazada<Automovil> automoviles = obtener_todo();

	for (Automovil automovil : automoviles) {
		if (Utilidades::cadenas_iguales(automovil.placa(), placa)) {
			return automovil;
		}
	}

	return std::nullopt;
}

std::optional<Automovil> ServicioAutomoviles::obtener_por_id(int id) {
	ListaDobleEnlazada<Automovil> automoviles = obtener_todo();

	for (Automovil automovil : automoviles) {
		if (automovil.id() == id) {
			return automovil;
		}
	}

	return std::nullopt;
}

void ServicioAutomoviles::crear(Automovil automovil) {
	ListaDobleEnlazada<Automovil> automoviles = obtener_todo();
	ListaDobleEnlazada<std::string> lineas;

	automoviles.insertar(automovil);

	for (Automovil automovil : automoviles) {
		std::stringstream linea;
		linea << automovil.id() << ",";
		linea << automovil.placa() << ",";
		linea << automovil.marca() << ",";
		linea << automovil.modelo() << ",";
		linea << automovil.color();
		lineas.insertar(linea.str());
	}

	Utilidades::escribirLineas("automoviles.txt", lineas, true);
}

void ServicioAutomoviles::actualizar(int id, Automovil automovil) {
	ListaDobleEnlazada<Automovil> automoviles = obtener_todo();
	ListaDobleEnlazada<std::string> lineas;

	for (Automovil a : automoviles) {
		Automovil registro = a;

		if (a.id() == id) {
			registro = automovil;
		}

		std::stringstream linea;
		linea << registro.id() << ",";
		linea << registro.placa() << ",";
		linea << registro.marca() << ",";
		linea << registro.modelo() << ",";
		linea << registro.color();
		lineas.insertar(linea.str());
	}

	Utilidades::escribirLineas("automoviles.txt", lineas, true);
}

bool ServicioAutomoviles::es_duenio(std::string cedula_duenio, int id_duenio) {
	io::CSVReader<2, io::trim_chars<' '>, io::double_quote_escape<',', '"'>> in("automoviles_personas.txt");

	std::string cedula;
	int id;

	while (in.read_row(cedula, id)) {
		if (Utilidades::cadenas_iguales(cedula, cedula_duenio) && id == id_duenio) {
			return true;
		}
	}

	return false;
}

int ServicioAutomoviles::ultimo_id() {
	ListaDobleEnlazada<Automovil> automoviles = obtener_todo();
	int ultimo_id = 0;

	for (Automovil automovil : automoviles) {
		if (automovil.id() > ultimo_id) {
			ultimo_id = automovil.id();
		}
	}

	return ultimo_id;
}
