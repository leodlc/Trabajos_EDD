/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES: Cristian Maranje
*Leonardo de la Cadena
*Johnny Loachamin
*Alvaro Zumba
*TEMA: Funciones lambda
*FECHA DE CREACION : 16 DE DICIEMBRE DEL 2021
*FECHA DE MODIFICACION: 16 DE DICIEMBRE DE 2021
* */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void StandardSort(vector<int>& vect)
{
    sort(vect.begin(), vect.end());
    cout << "Uso de el ordenamiento estándar" << endl;
    for_each(vect.begin(), vect.end(), [](int x) {cout << x << endl; });
}

void ProcessVector(vector<int>& vect)
{
    sort(vect.begin(), vect.end(), [](int S1, int S2) {return S1 > S2; });
    cout << "Utilizar un ordenamiento personalizado" << endl;
    for_each(vect.begin(), vect.end(), [](int x) {cout << x << endl; });
}

int main()
{
    vector<int> myV;
    myV.push_back(11);
    myV.push_back(2);
    myV.push_back(33);
    myV.push_back(4);

    StandardSort(myV);
    ProcessVector(myV);
}