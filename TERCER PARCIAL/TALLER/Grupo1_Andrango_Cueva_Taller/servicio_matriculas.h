#pragma once
#include "utilidades.h"
#include "lista_doble_enlazada.h"
#include "persona.h"
#include "automovil.h"
#include "matricula.h"
#include "servicio_personas.h"
#include "servicio_automoviles.h"
#include <fast-csv-parser/csv.h>

class ServicioMatriculas {
public:
	ServicioMatriculas() {
		Utilidades::crear_archivo("matriculas.txt");
	}
	
	ListaDobleEnlazada<Matricula> obtener_todo() {
		ListaDobleEnlazada<Matricula> matriculas;
		io::CSVReader<3, io::trim_chars<' '>, io::double_quote_escape<',', '"'>> in("matriculas.txt");

		std::string cedula;
		int id_automovil;
		std::string fecha;

		while (in.read_row(cedula, id_automovil, fecha)) {
			Persona persona = servicio_personas_.obtener(cedula).value();
			Automovil automovil = servicio_automoviles_.obtener_por_id(id_automovil).value();
			Fecha fechaFormateada = Fecha::parse(fecha);
			Provincia provincia = Provincia::Azuay;

			matriculas.insertar(Matricula(persona, automovil, fechaFormateada));
		}

		return matriculas;
	}

	std::string matricular(std::string cedula, int id, Provincia provincia, Fecha fecha) {
		Automovil automovil = servicio_automoviles_.obtener_por_id(id).value();
		std::string placa = generar_placa(provincia);
		automovil.placa(placa);
		servicio_automoviles_.actualizar(id, automovil);

		ListaDobleEnlazada<std::string> lineas;

		std::stringstream linea;
		linea << cedula << ",";
		linea << id << ",";
		linea << fecha.formatear("%d/%m/%Y");
		lineas.insertar(linea.str());

		Utilidades::escribirLineas("matriculas.txt", lineas, false);

		return placa;
	}

	std::string generar_placa(Provincia provincia) {
		ListaDobleEnlazada<Matricula> matriculas = obtener_todo();
		std::string placa;

		placa.push_back(static_cast<char>(provincia));
		placa += "AA0000";

		do {
			bool repetido = false;

			for (Matricula matricula : matriculas) {
				Automovil automovil = matricula.automovil();

				if (Utilidades::cadenas_iguales(automovil.placa(), placa)) {
					repetido = true;
					break;
				}
			}

			if (repetido) {
				std::string parte_numero;
				parte_numero.push_back(placa[3]);
				parte_numero.push_back(placa[4]);
				parte_numero.push_back(placa[5]);
				parte_numero.push_back(placa[6]);

				int numero = std::stoi(parte_numero);

				if (numero == 9999) {
					char segunda_letra = placa[1];
					char tercera_letra = placa[2];

					if (segunda_letra < 'Z') {
						segunda_letra = (segunda_letra + 1);
					} else {
						tercera_letra = (segunda_letra + 1);
					}

					placa[1] = segunda_letra;
					placa[2] = tercera_letra;
					numero = 0;
				} else {
					numero++;
				}

				std::stringstream ss;
				ss << placa[0] << placa[1] << placa[2];
				ss << std::setw(4) << std::setfill('0') << numero;
				placa = ss.str();

				std::cout << placa << std::endl;

				continue;
			}

			break;
		} while (true);

		return placa;
	}

	bool esta_matriculado(int id_automovil) {
		ListaDobleEnlazada<Matricula> matriculas = obtener_todo();
		
		for (Matricula matricula : matriculas) {
			if (matricula.automovil().id() == id_automovil) {
				return true;
			}
		}

		return false;
	}

private:
	ServicioAutomoviles servicio_automoviles_;
	ServicioPersonas servicio_personas_;
};