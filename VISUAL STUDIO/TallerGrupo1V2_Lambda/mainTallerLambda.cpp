/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES: Cristian Maranje
*Leonardo de la Cadena
*Johnny Loachamin
*Alvaro Zumba
*TEMA: mcm y mcd con funcion lambda
*FECHA DE CREACION : 15 DE DICIEMBRE DE 2021
*FECHA DE MODIFICACION: 19 DE DICIEMBRE DE 2021
* */
#include <iostream>
#include <string>
#include "FuncionLambda.h"

using namespace std;

void menuOpcion1();
void menuOpcion2();
void menuOpcion3();
void menuOpcion4();

void menuOpcion1() {
    int a;
    int b;
    int c;

    a = utils::leerEntero("ingresa el numero 1: ");
    b = utils::leerEntero("ingresa el numero 2: ");
    c = utils::leerEntero("ingresa el numero 3: ");

    int mcd = utils::calcularMaximoComunDivisor(a, b, c);
    std::cout << "Maximo comun divisor: " << mcd << std::endl;
}

void menuOpcion2() {
    std::vector<float> numbers;
    char option;

    do {
        int number;
        std::string input;
        std::cout << "Ingresa un numero o 'no' para salir: ";
        std::cin >> input;

        if (input == "no") {
            break;
        }

        try {
            number = std::stoi(input);
            numbers.push_back(number);
        }
        catch (std::invalid_argument) {
            continue;
        }

        numbers.push_back(number);
    } while (true);

    int mcd = utils::calcularMaximoComunDivisorN(numbers);
    std::cout << std::endl << "Maximo comun divisor: " << mcd << std::endl << std::endl;
}

void menuOpcion3() {
    std::vector<float> numbers;
    char option;

    do {
        int number;
        std::string input;
        std::cout << "Ingresa un numero o 'no' para salir: ";
        std::cin >> input;

        if (input == "no") {
            break;
        }

        try {
            number = std::stoi(input);
            numbers.push_back(number);
        }
        catch (std::invalid_argument) {
            continue;
        }

        numbers.push_back(number);
    } while (true);

    int mcm = utils::calcularMinimoComunMultiploN(numbers);
    std::cout << std::endl << "minimo comun multiplo: " << mcm << std::endl << std::endl;
}

void menuOpcion4() {
    int a;
    int b;
    int c;

    a = utils::leerEntero("ingresa el numero 1: ");
    b = utils::leerEntero("ingresa el numero 2: ");
    c = utils::leerEntero("ingresa el numero 3: ");

    int mcm = utils::calcularMinimoComunMultiplo(a, b, c);
    std::cout << "minimo comun multiplo: " << mcm << std::endl;
}


int main()
{
    int opcion;

    do {
        system("cls");
        cout << "1: Maximo comun divisor de 3 valores" << endl;
        cout << "2: Maximo comun divisor de n valores" << endl;
        cout << "3: Minimo comun multiplo de n valores" << endl;
        cout << "4: Minimo comun multiplo de 3 valores" << endl;
        cout << "5 Salir " << endl << endl;

        do {
            cout << "ingrese una opcion: ";
            cin >> opcion;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(9999, '\n');
            }
        } while (opcion < 1 || opcion > 5);

        cout << endl << endl;

        switch (opcion) {
        case 1:
        {
            menuOpcion1();
        }
        break;
        case 2:
        {
            menuOpcion2();
        }
        break;
        case 3:
        {
            menuOpcion3();
        }
        break;
        case 4:
        {
            menuOpcion4();
        }
        break;
        }

        if (opcion != 5) {
            cout << endl << endl;
            system("pause");
        }
    } while (opcion != 5);
}
