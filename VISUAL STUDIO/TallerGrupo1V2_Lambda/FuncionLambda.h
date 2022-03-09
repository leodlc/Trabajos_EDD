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
#pragma once
#include <functional>
#include <type_traits>
#include <vector>
#include <algorithm>
#include <cmath>

namespace utils
{
    int leerEntero(std::string mensaje) {
        int input;

        do {
            std::cout << mensaje;
            std::cin >> input;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(9999, '\n');
                continue;
            }

            break;
        } while (true);

        return input;
    }

    // funcion lambda para el maximo comun divisor
    const std::function<int(int, int)> gcd = [&](int a, int b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    };

    // Maximo comun divisor n valores para contenedores (std::vector, std::list, std::queue, etc)
    template<typename C,
        typename T = std::decay_t<
        decltype(*begin(std::declval<C>()))>,
        typename = std::enable_if_t<
        std::is_convertible_v<T, int>>>
        int calcularMaximoComunDivisorN(C const& list) {
        std::vector<int> vec = { list.begin(), list.end() };
        int result = vec.at(0);

        vec.erase(vec.begin());

        for (auto i : vec) {
            result = gcd(i, result);

            if (result == 1) return 1;
        }

        return result;
    }

    // Maximo comun divisor n valores ...
    template <typename... Args>
    int calcularMaximoComunDivisorN(Args... args) {
        return calcularMaximoComunDivisorN(std::vector<int>{args...});
    }
    int calcularMaximoComunDivisorN(std::initializer_list<int> list) {
        return calcularMaximoComunDivisorN(std::vector<int>{list});
    }

    // Maximo comun divisor 3 valores
    int calcularMaximoComunDivisor(int a, int b, int c) {
        auto fn = [](int a, int b, int c) -> int {
            int maxi = 0;

            maxi = std::max(a, std::max(b, c));

            for (int i = maxi; i > 1; i--) {
                if ((a % i == 0) and (b % i == 0) and (c % i == 0)) {
                    return i;
                    break;
                }
            }

            return 1;
        };

        return fn(a, b, c);
    }


    // minimo comun multiplo n valores 
    template<typename C,
        typename T = std::decay_t<decltype(*begin(std::declval<C>()))>,
        typename = std::enable_if_t<std::is_convertible_v<T, int>>
    >
        int calcularMinimoComunMultiploN(C const& list) {
        std::vector<int> vec = { list.begin(), list.end() };
        int result = vec.at(0);

        vec.erase(vec.begin());

        for (auto i : vec) {
            result = (((i * result)) / (gcd(i, result)));
        }

        return result;
    }
    template <typename... Args>
    int calcularMinimoComunMultiploN(Args... args) {
        return calcularMaximoComunDivisorN(std::vector<int>{args...});
    }


    int calcularMinimoComunMultiploN(std::initializer_list<int> list) {
        return calcularMinimoComunMultiploN(std::vector<int>{list});
    }

    // minimo comun multiplo de  3 valores
    int calcularMinimoComunMultiplo(int a, int b, int c) {
        auto fn = [](int x, int y, int z) -> int {
            long max, lcom, count, flag = 0;
            if (x >= y && x >= z)
                max = x;
            else if (y >= x && y >= z)
                max = y;
            else if (z >= x && z >= y)
                max = z;
            for (count = 1; flag == 0; count++) {
                lcom = max * count;
                if (lcom % x == 0 && lcom % y == 0 && lcom % z == 0) {
                    flag = 1;
                }
            }

            return lcom;
        };

        return fn(a, b, c);
    }
};
