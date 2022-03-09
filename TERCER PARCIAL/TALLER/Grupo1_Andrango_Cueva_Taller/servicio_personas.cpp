/**************************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*TITULO: TALLER - MATRICULACION DE AUTOS
*AUTOR(ES): LUIS CUEVA, CHRISTIAN ANDRANGO
*FECHA: SABADO 26 DE FEBRERO DE 2022
*VERSION: 1
*ESTRUCTURA DE DATOS
*NRC: 7166
***************************************************************************/

#include "servicio_personas.h"
#include "utilidades.h"
#include <fast-csv-parser/csv.h>

ServicioPersonas::ServicioPersonas() {
	Utilidades::crear_archivo("personas.txt");
	Utilidades::crear_archivo("automoviles_personas.txt");
}

ListaDobleEnlazada<Persona> ServicioPersonas::obtener_todo() {
	ListaDobleEnlazada<Persona> personas;
	io::CSVReader<3, io::trim_chars<' '>, io::double_quote_escape<',', '"'>> in("personas.txt");

	std::string cedula;
	std::string nombres;
	std::string apellidos;

	while (in.read_row(cedula, nombres, apellidos)) {
		Persona persona(cedula, nombres, apellidos);
		ListaEnlazada<Automovil> automoviles = obtener_automoviles(cedula);

		automoviles.recorrer([&](Automovil automovil) {
			persona.agregar_automovil(automovil);
		});
		
		personas.insertar(persona);
	}

	return personas;
}

std::optional<Persona> ServicioPersonas::obtener(std::string cedula) {
	ListaDobleEnlazada<Persona> personas = obtener_todo();

	for (Persona persona : personas) {
		if (Utilidades::cadenas_iguales(persona.cedula(), cedula)) {
			return persona;
		}
	}

	return std::nullopt;
}

void ServicioPersonas::crear(Persona persona) {
	ListaDobleEnlazada<Persona> personas = obtener_todo();
	ListaDobleEnlazada<std::string> lineas;

	personas.insertar(persona);

	for (Persona persona : personas) {
		std::stringstream linea;
		linea << persona.cedula() << ",";
		linea << persona.nombres() << ",";
		linea << persona.apellidos();
		lineas.insertar(linea.str());
	}

	Utilidades::escribirLineas("personas.txt", lineas, true);
}

ListaEnlazada<Automovil> ServicioPersonas::obtener_automoviles(std::string cedula_persona) {
	ListaEnlazada<Automovil> automoviles;
	io::CSVReader<2, io::trim_chars<' '>, io::double_quote_escape<',', '"'>> in("automoviles_personas.txt");

	std::string cedula;
	int id;

	while (in.read_row(cedula, id)) {
		if (Utilidades::cadenas_iguales(cedula, cedula_persona)) {
			auto automovil = servicio_automoviles_.obtener_por_id(id);

			if (automovil.has_value()) {
				automoviles.insertar(automovil.value());
			}
		}
	}

	return automoviles;
}

void ServicioPersonas::agregar_automovil(std::string cedula, Automovil automovil) {
	ListaDobleEnlazada<std::string> lineas;

	std::stringstream linea;
	linea << cedula << ",";
	linea << automovil.id();
	lineas.insertar(linea.str());

	Utilidades::escribirLineas("automoviles_personas.txt", lineas, false);
}
