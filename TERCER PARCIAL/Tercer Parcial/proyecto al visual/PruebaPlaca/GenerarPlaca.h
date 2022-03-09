//#pragma once
//
//#include "Provincia.h"
//
//#include <string>
//#include <iostream>
//#include <fstream>
//#include <algorithm>
//#include <limits>
//#include <random>
//#include <cctype>
//#include <regex>
//#include <iomanip>
//#include <sstream>
//#include <cfloat>
//#include <regex>
//#include <map>
//
//
//static int leer_entero(std::string etiqueta, int minimo = INT_MIN, int maximo = INT_MAX) {
//	int leido;
//	bool valido;
//
//	do {
//		std::cout << etiqueta;
//		std::cin >> leido;
//
//		valido = !std::cin.fail();
//
//		std::cin.clear();
//		std::cin.ignore();
//	} while (!valido || leido < minimo || leido > maximo);
//
//	return leido;
//}
//
//static inline Provincia seleccionar_provincia(std::string label) {
//	int i = 0;
//	auto mapa_nombres = provincias_nombres();
//	std::vector<Provincia> provincias;
//
//	std::cout << std::endl
//		<< std::endl;
//
//	for (auto item : mapa_nombres) {
//		auto provincia = item.first;
//		auto nombre = item.second;
//
//		std::cout << i << ": " << nombre << std::endl;
//		provincias.push_back(provincia);
//		i++;
//	}
//
//	std::cout << std::endl;
//	int posicion = leer_entero(label, 1, i);
//	auto seleccionado = provincias.at(posicion);
//
//	return seleccionado;
//}
//
//static inline std::string nombre_provincia(Provincia provincia) {
//	return provincias_nombres().at(provincia);
//}
//
//static inline Provincia provincia_por_codigo(int codigo) {
//	std::map<int, Provincia> codigos;
//
//	codigos.insert({ 1, Provincia::Azuay });
//	codigos.insert({ 2, Provincia::Bolivar });
//	codigos.insert({ 3, Provincia::Caniar });
//	codigos.insert({ 4, Provincia::Carchi });
//	codigos.insert({ 5, Provincia::Cotopaxi });
//	codigos.insert({ 6, Provincia::Chimborazo });
//	codigos.insert({ 7, Provincia::ElOro });
//	codigos.insert({ 8, Provincia::Esmeraldas });
//	codigos.insert({ 9, Provincia::Guayas });
//	codigos.insert({ 10, Provincia::Imbabura });
//	codigos.insert({ 11, Provincia::Loja });
//	codigos.insert({ 12, Provincia::LosRios });
//	codigos.insert({ 13, Provincia::Manabi });
//	codigos.insert({ 14, Provincia::MoronaSantiago });
//	codigos.insert({ 15, Provincia::Napo });
//	codigos.insert({ 16, Provincia::Pastaza });
//	codigos.insert({ 17, Provincia::Pichincha });
//	codigos.insert({ 18, Provincia::Tungurahua });
//	codigos.insert({ 19, Provincia::ZamoraChinchipe });
//	codigos.insert({ 20, Provincia::Galapagos });
//	codigos.insert({ 21, Provincia::Sucumbios });
//	codigos.insert({ 22, Provincia::Orellana });
//	codigos.insert({ 23, Provincia::SantoDomingo });
//	codigos.insert({ 24, Provincia::SantaElena });
//
//	return codigos.at(codigo);
//}
//
//static inline std::map<Provincia, std::string> provincias_nombres() {
//	std::map<Provincia, std::string> nombres;
//
//	nombres.insert({ Provincia::Azuay, "Azuay" });
//	nombres.insert({ Provincia::Bolivar, "Bolivar" });
//	nombres.insert({ Provincia::Caniar, "Caniar" });
//	nombres.insert({ Provincia::Carchi, "Carchi" });
//	nombres.insert({ Provincia::Cotopaxi, "Cotopaxi" });
//	nombres.insert({ Provincia::Chimborazo, "Chimborazo" });
//	nombres.insert({ Provincia::ElOro, "El oro" });
//	nombres.insert({ Provincia::Esmeraldas, "Esmeraldas" });
//	nombres.insert({ Provincia::Guayas, "Guayas" });
//	nombres.insert({ Provincia::Imbabura, "Imbabura" });
//	nombres.insert({ Provincia::Loja, "Loja" });
//	nombres.insert({ Provincia::LosRios, "Los rios" });
//	nombres.insert({ Provincia::Manabi, "Manabi" });
//	nombres.insert({ Provincia::MoronaSantiago, "Morona Santiago" });
//	nombres.insert({ Provincia::Napo, "Napo" });
//	nombres.insert({ Provincia::Pastaza, "Pastaza" });
//	nombres.insert({ Provincia::Pichincha, "Pichincha" });
//	nombres.insert({ Provincia::Tungurahua, "Tungurahua" });
//	nombres.insert({ Provincia::ZamoraChinchipe, "Zamora Chinchipe" });
//	nombres.insert({ Provincia::Galapagos, "Galapagos" });
//	nombres.insert({ Provincia::Sucumbios, "Sucumbios" });
//	nombres.insert({ Provincia::Orellana, "Orellana" });
//	nombres.insert({ Provincia::SantoDomingo, "Santo domingo" });
//	nombres.insert({ Provincia::SantaElena, "Santa Elena" });
//
//	return nombres;
//}