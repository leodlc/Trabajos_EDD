/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES: Cristian Maranje
*Leonardo de la Cadena
*Johnny Loachamin
*Alvaro Zumba
*TEMA: Funciones lambda
*FECHA DE CREACION : 14 DE DICIEMBRE DEL 2021
*FECHA DE MODIFICACION: 14 DE DICIEMBRE DE 2021
* */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Multiplo {

	int mul;

public:
	Multiplo(int multi) :mul(multi) {}
	bool operator() (int x)
	{
		return !(x % mul);
	}
};
int main()
{
	vector<int> vec = { 1,3,5,7,9,8,6,4,12 };
	int multi = 4;
	int tam;
	sizeof tam;
	tam = count_if(vec.begin(), vec.end(), [multi](int x) {
		return !(x % multi); });
	cout << "enteros multiplos de " << multi << ": " << tam << endl;

}