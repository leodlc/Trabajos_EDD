/**************************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*TITULO: TALLER - MATRICULACION DE AUTOS
*AUTOR(ES): LUIS CUEVA, CHRISTIAN ANDRANGO
*FECHA: SABADO 26 DE FEBRERO DE 2022
*VERSION: 1
*ESTRUCTURA DE DATOS
*NRC: 7166
***************************************************************************/
#include "aplicacion.h"
#include "Menu.h"
#include "fecha.hpp"
#include "utilidades.h"
#include <libfort/fort.hpp>

void Aplicacion::iniciar() {
	Menu menu("Automoviles matriculacion");
	menu.add(MenuItem("Registrar una persona", std::bind(&Aplicacion::menu_agregar_persona, this)));
	menu.add(MenuItem("Registrar un automovil", std::bind(&Aplicacion::menu_agregar_automovil, this)));
	menu.add(MenuItem("Asignar un automovil a una persona", std::bind(&Aplicacion::menu_asignar_automovil, this)));
	menu.add(MenuItem("Registro de matricula", std::bind(&Aplicacion::menu_registro_matricula, this)));
	menu.add(MenuItem("Imprimir personas", std::bind(&Aplicacion::menu_imprimir_personas, this)));
	menu.add(MenuItem("Imprimir autos", std::bind(&Aplicacion::menu_imprimir_automoviles, this)));
	menu.add(MenuItem("Imprimir personas con autos", std::bind(&Aplicacion::menu_imprimir_automoviles_personas, this)));
	menu.add(menu.exit_item("Salir"));
	menu.run();
}

void Aplicacion::menu_agregar_persona() {
	std::string cedula;
	std::string nombres;
	std::string apellidos;

	while (true) {
		cedula = Utilidades::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");

		if (!Utilidades::cedula_valida(cedula)) {
			Utilidades::mostrar_mensaje("Cedula invalida", TipoMensaje::Error);
			continue;
		}

		if (servicio_personas_.obtener(cedula).has_value()) {
			Utilidades::mostrar_mensaje("Cedula ya registrada", TipoMensaje::Error);
			continue;
		}

		break;
	}

	nombres = Utilidades::leer_cadena_regex("Ingresa los nombres: ", "^([a-zA-Z ]+)$");
	apellidos = Utilidades::leer_cadena_regex("Ingresa los apellidos: ", "^([a-zA-Z ]+)$");

	servicio_personas_.crear(Persona(cedula, nombres, apellidos));
	Utilidades::mostrar_mensaje("Usuario creado con exito", TipoMensaje::Correcto);
}

void Aplicacion::menu_agregar_automovil() {
	int id = servicio_automoviles_.ultimo_id() + 1;
	std::string placa = "";
	std::string marca = Utilidades::leer_cadena("Ingresa la marca: ");
	std::string modelo = Utilidades::leer_cadena("Ingresa la modelo: ");
	std::string color = Utilidades::leer_cadena("Ingresa el color: ");

	servicio_automoviles_.crear(Automovil(id, placa, marca, modelo, color));
	Utilidades::mostrar_mensaje("Automovil creado con exito", TipoMensaje::Correcto);
}

void Aplicacion::menu_imprimir_personas() {
	ListaDobleEnlazada<Persona> personas = servicio_personas_.obtener_todo();
	fort::table tabla;
	
	if (personas.vacio()) {
		Utilidades::mostrar_mensaje("No se encontraron automoviles registrados");
		return;
	}

	tabla << fort::header
		  << "Cedula"
		  << "nombres"
		  << "Apellidos"
		  << fort::endr;

	personas.recorrer([&](Persona persona) {
		tabla << persona.cedula() << persona.nombres() << persona.apellidos() << fort::endr;	
	});

	std::cout << tabla.to_string() << std::endl;
}

void Aplicacion::menu_imprimir_automoviles() {
	ListaDobleEnlazada<Automovil> automoviles = servicio_automoviles_.obtener_todo();
	fort::table tabla;

	if (automoviles.vacio()) {
		Utilidades::mostrar_mensaje("No se encontraro automoviles registrados");
		return;
	}

	tabla << fort::header
		  << "ID"
		  << "Placa"
		  << "Marca"
		  << "Modelo"
		  << "Color"
		  << "Matriculado"
		  << fort::endr;

	automoviles.recorrer([&](Automovil automovil) {
		tabla << automovil.id();
		tabla << (automovil.placa().empty() ? "-" : automovil.placa());
		tabla << automovil.marca();
		tabla << automovil.modelo();
		tabla << automovil.color();
		
		if (servicio_matriculas_.esta_matriculado(automovil.id())) {
			tabla << "SI";
		} else {
			tabla << "NO";
		}

		tabla << fort::endr;
	});

	std::cout << tabla.to_string() << std::endl;
}

void Aplicacion::menu_asignar_automovil() {
	std::string cedula;
	int id = 0;

	if (servicio_personas_.obtener_todo().vacio()) {
		Utilidades::mostrar_mensaje("No se encontraron personas registrados");
		return;
	}

	if (servicio_automoviles_.obtener_todo().vacio()) {
		Utilidades::mostrar_mensaje("No se encontraron automoviles registrados");
		return;
	}

	std::cout << std::endl
			  << std::endl;
	menu_imprimir_personas();
	std::cout << std::endl
			  << std::endl;

	while (true) {
		cedula = Utilidades::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");

		if (!Utilidades::cedula_valida(cedula)) {
			Utilidades::mostrar_mensaje("Cedula invalida", TipoMensaje::Error);
			continue;
		}

		if (!servicio_personas_.obtener(cedula).has_value()) {
			Utilidades::mostrar_mensaje("La cedula ingresada no pertenece a una persona registrada", TipoMensaje::Error);
			continue;
		}

		break;
	}
	
	std::cout << std::endl
			  << std::endl;
	menu_imprimir_automoviles();
	std::cout << std::endl
			  << std::endl;

	ListaDobleEnlazada<Automovil> automoviles = servicio_automoviles_.obtener_todo();
	id = Utilidades::leer_entero("Ingrese el ID del automovil: ", 1, automoviles.tamanio());

	if (!servicio_automoviles_.obtener_por_id(id).has_value()) {
		Utilidades::mostrar_mensaje("El ID ingresado no existe");
		return;
	}

	if (servicio_automoviles_.es_duenio(cedula, id)) {
		Utilidades::mostrar_mensaje("La persona ya tiene este vehiculo en su posesion");
		return;
	}

	servicio_personas_.agregar_automovil(cedula, servicio_automoviles_.obtener_por_id(id).value());
	Utilidades::mostrar_mensaje("Automovil asignado correctamente", TipoMensaje::Correcto);
}

void Aplicacion::menu_registro_matricula() {
	std::string cedula;
	int id = 0;

	if (servicio_personas_.obtener_todo().vacio()) {
		Utilidades::mostrar_mensaje("No se encontraron personas registrados");
		return;
	}

	if (servicio_automoviles_.obtener_todo().vacio()) {
		Utilidades::mostrar_mensaje("No se encontraron automoviles registrados");
		return;
	}

	std::cout << std::endl
			  << std::endl;
	menu_imprimir_personas();
	std::cout << std::endl
			  << std::endl;

	while (true) {
		cedula = Utilidades::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");

		if (!Utilidades::cedula_valida(cedula)) {
			Utilidades::mostrar_mensaje("Cedula invalida", TipoMensaje::Error);
			continue;
		}

		if (!servicio_personas_.obtener(cedula).has_value()) {
			Utilidades::mostrar_mensaje("La cedula ingresada no pertenece a una persona registrada", TipoMensaje::Error);
			continue;
		}

		break;
	}

	std::cout << std::endl
			  << std::endl;
	menu_imprimir_automoviles();
	std::cout << std::endl
			  << std::endl;

	ListaDobleEnlazada<Automovil> automoviles = servicio_automoviles_.obtener_todo();
	id = Utilidades::leer_entero("Ingrese el ID del automovil: ", 1, automoviles.tamanio());

	if (!servicio_automoviles_.obtener_por_id(id).has_value()) {
		Utilidades::mostrar_mensaje("El ID ingresado no existe");
		return;
	}

	if (!servicio_automoviles_.es_duenio(cedula, id)) {
		Utilidades::mostrar_mensaje("La persona no es duenio de este vehiculo");
		return;
	}

	Fecha fecha = Fecha::ingresar();
	Provincia provincia;

	if (INTUIR_PROVINCIA_POR_CEDULA) {
		std::string digitos_provincia;
		digitos_provincia.push_back(cedula.at(0));
		digitos_provincia.push_back(cedula.at(1));

		int codigo = std::stoi(digitos_provincia);
		provincia = Utilidades::provincia_por_codigo(codigo);
	} else {
		provincia = Utilidades::seleccionar_provincia("Seleccione la provincia: ");
	}

	std::string placa = servicio_matriculas_.matricular(cedula, id, provincia, fecha);
	Utilidades::mostrar_mensaje("Vehiculo matriculado con la placa: " + placa);
}

void Aplicacion::menu_imprimir_automoviles_personas() {
	auto personas = servicio_personas_.obtener_todo();
	fort::table tabla;

	if (personas.vacio()) {
		Utilidades::mostrar_mensaje("No se encontraro personas registradas");
		return;
	}

	tabla << fort::header
		  << "Cedula"
		  << "Nombre"
		  << "Placa"
		  << "Marca"
		  << "Modelo"
		  << "Color"
		  << "Matriculado"
		  << fort::endr;

	for (Persona persona : personas) {
		persona.automoviles().recorrer([&](Automovil automovil) {
			tabla << persona.cedula();
			tabla << persona.nombres() + " " + persona.apellidos();
			tabla << automovil.placa();
			tabla << automovil.marca();
			tabla << automovil.modelo();
			tabla << automovil.color();

			if (servicio_matriculas_.esta_matriculado(automovil.id())) {
				tabla << "SI";
			} else {
				tabla << "NO";
			}

			tabla << fort::endr;
		});
	}

	std::cout << tabla.to_string() << std::endl;
}
