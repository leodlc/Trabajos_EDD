/**************************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*TITULO: TALLER - MATRICULACION DE AUTOS
*AUTOR(ES): LUIS CUEVA, CHRISTIAN ANDRANGO
*FECHA: SABADO 26 DE FEBRERO DE 2022
*VERSION: 1
*ESTRUCTURA DE DATOS
*NRC: 7166
***************************************************************************/
#pragma once
#include "lista_doble_enlazada.h"
#include "definiciones.h"
#include "provincia.h"

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <random>
#include <cctype>
#include <regex>
#include <iomanip>
#include <sstream>
#include <cfloat>
#include <regex>
#include <map>
#include <rang/rang.hpp>

class Utilidades {
public:
	static std::string leer_cadena(const std::string etiqueta, bool permitir_vacio = false) {
		std::string leido;

		if (permitir_vacio) {
			std::getline(std::cin, leido);
		} else {
			while ((std::cout << etiqueta),
				std::getline(std::cin, leido), leido.empty())
				;
		}

		return leido;
	}

	static std::string leer_cadena_regex(const std::string etiqueta, std::string regex) {
		std::string leido;
		std::regex cadena_regex(regex);

		do {
			leido = leer_cadena(etiqueta);

			if (!std::regex_match(leido, cadena_regex)) {
				mostrar_mensaje("Formato invalido", TipoMensaje::Error);
			}
		} while (!std::regex_match(leido, cadena_regex));

		return leido;
	}

	static int leer_entero(std::string etiqueta, int minimo = INT_MIN, int maximo = INT_MAX) {
		int leido;
		bool valido;

		do {
			std::cout << etiqueta;
			std::cin >> leido;

			valido = !std::cin.fail();

			std::cin.clear();
			std::cin.ignore();
		} while (!valido || leido < minimo || leido > maximo);

		return leido;
	}

	static bool cadenas_iguales(std::string a, std::string b) {
		a = trim_cadena(cadena_minusculas(a));
		b = trim_cadena(cadena_minusculas(b));

		return a == b;
	}

	static double leer_flotante(std::string etiqueta, double minimo = DBL_MIN, double maximo = DBL_MAX) {
		double leido;
		bool valido;

		do {
			std::cout << etiqueta;
			std::cin >> leido;

			valido = !std::cin.fail();

			std::cin.clear();
			std::cin.ignore();
		} while (!valido || leido < minimo || leido > maximo);

		return leido;
	}

	static bool cedula_valida(const std::string cedula) {
		if (cedula.length() != 10) {
			return false;
		}

		int sum_par = 0;
		int sum_impar = 0;
		int sum;
		int i = 1;

		std::string digits = cedula.substr(0, cedula.size() - 1);

		for (char& c : digits) {
			int digit = c - '0';
			if (i % 2 == 0) {
				sum_par += digit;
			} else {
				if ((digit * 2) > 9) {
					sum_impar += (digit * 2) - 9;
				} else {
					sum_impar += (digit * 2);
				}
			}
			i++;
		}

		sum = sum_par + sum_impar;

		int verifier = cedula.at(cedula.size() - 1) - '0';
		int higher = (10 - (sum % 10)) + sum;

		if (sum % 10 == 0) {
			return verifier == 0;
		}

		return (higher - sum) == verifier;
	}

	static ListaDobleEnlazada<std::string> dividir_cadena(std::string cadena, std::string delimitador) {
		ListaDobleEnlazada<std::string> partes;
		size_t start = 0;
		auto end = cadena.find(delimitador);

		while (end != std::string::npos) {
			partes.insertar(cadena.substr(start, end - start));
			start = end + delimitador.length();
			end = cadena.find(delimitador, start);
		}

		partes.insertar(cadena.substr(start, end));
		return partes;
	}

	static std::string trim_cadena(std::string cadena) {
		auto wsfront = std::find_if_not(cadena.begin(), cadena.end(), [](int c) { return std::isspace(c); });
		auto wsback = std::find_if_not(cadena.rbegin(), cadena.rend(), [](int c) { return std::isspace(c); }).base();
		return (wsback <= wsfront ? std::string() : std::string(wsfront, wsback));
	}

	static void leer_lineas(
		std::string nombre_archivo,
		std::function<void(std::string linea, ListaDobleEnlazada<std::string> datos)> callback) {
		std::ifstream archivo(nombre_archivo);
		std::string linea;

		while (std::getline(archivo, linea)) {
			linea = Utilidades::trim_cadena(linea);

			if (linea.empty()) {
				continue;
			}

			auto columnas = Utilidades::dividir_cadena(linea, ",");

			columnas.transformar([](std::string token) {
				return Utilidades::trim_cadena(token);
			});

			callback(linea, columnas);
		}

		archivo.close();
	}

	static std::string cadena_minusculas(std::string cadena) {
		std::transform(cadena.begin(), cadena.end(), cadena.begin(), [](unsigned char c) {
			return std::tolower(c);
		});

		return cadena;
	}

	static void mostrar_mensaje(std::string mensaje, TipoMensaje tipo = TipoMensaje::Informativo) {
		rang::fg color;

		if (tipo == TipoMensaje::Informativo) {
			color = rang::fg::cyan;
		} else if (tipo == TipoMensaje::Correcto) {
			color = rang::fg::green;
		} else if (tipo == TipoMensaje::Error) {
			color = rang::fg::red;
		} else {
			color = rang::fg::cyan;
		}

		std::cout
			<< std::endl << rang::style::bold << color
			<< "(" << mensaje << ")"
			<< std::endl << rang::style::reset;
	}

	static bool existe_archivo(std::string nombre_archivo) {
		return std::ifstream(nombre_archivo.c_str()).good();
	}

	static int generar_aleatorio(int minimo = INT_MIN, int maximo = INT_MAX) {
		std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(minimo, maximo);

		return dis(gen);
	}

	static bool confirmar(std::string pregunta) {
		char respuesta = 'n';
		std::string entrada;

		do {
			std::cout << pregunta << " (s/n): ";
			std::cin >> entrada;

			std::cin.clear();
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

			if (entrada.length() > 1) continue;

			respuesta = std::tolower(entrada.at(0));
		} while (respuesta != 's' && respuesta != 'n');

		return (respuesta == 's');
	}

	static std::string decimal_fixed(float valor, int precision = 2) {
		std::stringstream ss;
		ss << std::fixed << std::setprecision(precision) << valor;
		return ss.str();
	}

	/*
	 * Verifica si un archivo existe o no
	 * @param ruta la ruta del archivo a verificar
	 */
	static bool archivo_existe(std::string ruta) {
		GetFileAttributesA(ruta.c_str());
		return !(INVALID_FILE_ATTRIBUTES == GetFileAttributesA(ruta.c_str()) && GetLastError() == ERROR_FILE_NOT_FOUND);
	}

	/*
	 * Crea un archivo si no existe
	 * @param ruta la ruta del archivo a crear
	 */
	static void crear_archivo(std::string ruta) {
		std::fstream archivo;
		archivo.open(ruta, std::fstream::in | std::fstream::out | std::fstream::app);
		archivo.close();
	}

	static inline ListaDobleEnlazada<std::string> leerLineas(std::string ruta) {
		ListaDobleEnlazada<std::string> lineas;
		std::ifstream archivo(ruta);
		std::string linea;

		while (std::getline(archivo, linea)) {
			lineas.insertar(linea);
		}

		archivo.close();
		return lineas;
	}

	static inline ListaDobleEnlazada<ListaDobleEnlazada<std::string>> leerCSV(std::string ruta) {
		ListaDobleEnlazada<ListaDobleEnlazada<std::string>> csv;
		ListaDobleEnlazada<std::string> lineas = leerLineas(ruta);

		for (std::string linea : lineas) {
			linea = trim_cadena(linea);
			ListaDobleEnlazada<std::string> columnas;
			std::stringstream ss(linea);
			std::string columna;

			while (std::getline(ss, columna, ',')) {
				columna = trim_cadena(columna);
				columnas.insertar(columna);
			}

			csv.insertar(columnas);
		}

		return csv;
	}

	static inline void escribirLineas(std::string ruta, ListaDobleEnlazada<std::string> lineas, bool sobreescribir = true) {
		std::ofstream archivo(ruta, (sobreescribir ? std::ios::trunc : std::ios::app));

		for (std::string linea : lineas) {
			archivo << linea;

			if (linea.back() != '\n') {
				archivo << std::endl;
			}
		}

		archivo.close();
	}

	static inline Provincia seleccionar_provincia(std::string label) {
		int i = 0;
		auto mapa_nombres = provincias_nombres();
		std::vector<Provincia> provincias;

		std::cout << std::endl
				  << std::endl;

		for (auto item : mapa_nombres) {
			auto provincia = item.first;
			auto nombre = item.second;

			std::cout << i << ": " << nombre << std::endl;
			provincias.push_back(provincia);
			i++;
		}
		
		std::cout << std::endl;
		int posicion = leer_entero(label, 1, i);
		auto seleccionado = provincias.at(posicion);

		return seleccionado;
	}

	static inline std::string nombre_provincia(Provincia provincia) {
		return provincias_nombres().at(provincia);
	}

	static inline Provincia provincia_por_codigo(int codigo) {
		std::map<int, Provincia> codigos;

		codigos.insert({ 1, Provincia::Azuay });
		codigos.insert({ 2, Provincia::Bolivar });
		codigos.insert({ 3, Provincia::Caniar });
		codigos.insert({ 4, Provincia::Carchi });
		codigos.insert({ 5, Provincia::Cotopaxi });
		codigos.insert({ 6, Provincia::Chimborazo });
		codigos.insert({ 7, Provincia::ElOro });
		codigos.insert({ 8, Provincia::Esmeraldas });
		codigos.insert({ 9, Provincia::Guayas });
		codigos.insert({ 10, Provincia::Imbabura });
		codigos.insert({ 11, Provincia::Loja });
		codigos.insert({ 12, Provincia::LosRios });
		codigos.insert({ 13, Provincia::Manabi });
		codigos.insert({ 14, Provincia::MoronaSantiago });
		codigos.insert({ 15, Provincia::Napo });
		codigos.insert({ 16, Provincia::Pastaza });
		codigos.insert({ 17, Provincia::Pichincha });
		codigos.insert({ 18, Provincia::Tungurahua });
		codigos.insert({ 19, Provincia::ZamoraChinchipe });
		codigos.insert({ 20, Provincia::Galapagos });
		codigos.insert({ 21, Provincia::Sucumbios });
		codigos.insert({ 22, Provincia::Orellana });
		codigos.insert({ 23, Provincia::SantoDomingo });
		codigos.insert({ 24, Provincia::SantaElena });

		return codigos.at(codigo);
	}

	static inline std::map<Provincia, std::string> provincias_nombres() {
		std::map<Provincia, std::string> nombres;

		nombres.insert({ Provincia::Azuay, "Azuay" });
		nombres.insert({ Provincia::Bolivar, "Bolivar" });
		nombres.insert({ Provincia::Caniar, "Caniar" });
		nombres.insert({ Provincia::Carchi, "Carchi" });
		nombres.insert({ Provincia::Cotopaxi, "Cotopaxi" });
		nombres.insert({ Provincia::Chimborazo, "Chimborazo" });
		nombres.insert({ Provincia::ElOro, "El oro" });
		nombres.insert({ Provincia::Esmeraldas, "Esmeraldas" });
		nombres.insert({ Provincia::Guayas, "Guayas" });
		nombres.insert({ Provincia::Imbabura, "Imbabura" });
		nombres.insert({ Provincia::Loja, "Loja" });
		nombres.insert({ Provincia::LosRios, "Los rios" });
		nombres.insert({ Provincia::Manabi, "Manabi" });
		nombres.insert({ Provincia::MoronaSantiago, "Morona Santiago" });
		nombres.insert({ Provincia::Napo, "Napo" });
		nombres.insert({ Provincia::Pastaza, "Pastaza" });
		nombres.insert({ Provincia::Pichincha, "Pichincha" });
		nombres.insert({ Provincia::Tungurahua, "Tungurahua" });
		nombres.insert({ Provincia::ZamoraChinchipe, "Zamora Chinchipe" });
		nombres.insert({ Provincia::Galapagos, "Galapagos" });
		nombres.insert({ Provincia::Sucumbios, "Sucumbios" });
		nombres.insert({ Provincia::Orellana, "Orellana" });
		nombres.insert({ Provincia::SantoDomingo, "Santo domingo" });
		nombres.insert({ Provincia::SantaElena, "Santa Elena" });

		return nombres;
	}
};
