#include <iostream>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <functional>
#include <type_traits>
#include <vector>
#include <algorithm>
#include <cmath>
#include "Nargumento.h"
using namespace std;

int mcm(int x, int y, int z)
{
    long max, lcom, cnta, flag = 0;
    if (x >= y && x >= z)
        max = x;
    else if (y >= x && y >= z)
        max = y;
    else if (z >= x && z >= y)
        max = z;
    for (cnta = 1; flag == 0; cnta++)
    {
        lcom = max * cnta;
        if (lcom % x == 0 && lcom % y == 0 && lcom % z == 0)
        {
            flag = 1;
        }
    }
    return lcom;
}
int mcd(int p, int q, int r)
{
    int gcf = 1, flag = 0, cnta;
    for (cnta = 1; flag == 0; cnta++)
    {
        if (p % cnta == 0 && q % cnta == 0 && r % cnta == 0)
            gcf = cnta;
        if (cnta > p && cnta > q && cnta > r)
        {
            flag = 1;
        }
    }
    return gcf;
}


int main()
{
    int num1, num2, num3;
    
    auto rmcm = [&num1,&num2,&num3](int& maxdiv)->int {

        return mcm(num1, num2, num3);
    };
    auto rmcd = [&num1, &num2, &num3](int& minMul)->int {

        return mcd(num1, num2, num3);
    };

    int maxDiv=0;
    int minMul = 0;
    cout << "ingrese el primer numero: ";
    cin >> num1;
    cout << "ingrese el segundo numero: ";
    cin >> num2;
    cout << "ingrese el tercer numero: ";
    cin >> num3;
    cout << "El minimo comun multiplo es es: " << rmcm(maxDiv) << endl;
    cout << "El minimo comun multiplo es es: " << rmcd(minMul) << endl;
    vector<float> numeros;

    do {
        int numero;
        std::string input;
        std::cout << "Ingresa un numero o 'no' para salir: ";
        std::cin >> input;

        if (input == "no") {
            break;
        }

        try {
            //numero = stoi(input);
            numeros.push_back(numero);
        }
        catch (std::invalid_argument) {
            continue;
        }

        numeros.push_back(numero);

    } while (true);
    int maxDivN = calcularMaxDivNargs(numeros);
    cout << "Maximo comun divisor de los numeros ingresados: " << maxDivN << endl;

    return 0;
    
}

