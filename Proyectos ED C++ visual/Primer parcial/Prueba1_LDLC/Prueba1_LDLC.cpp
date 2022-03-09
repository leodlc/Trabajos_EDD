#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORE: Leonardo de la Cadena
*TEMA: Prueba 1
*FECHA DE CREACION : 15 DE NOVIEMBRE DEL 2021
*FECHA DE MODIFICACION: 15 DE NOVIEMBRE DE 2021
* */

void segmentar();
void encerar();
void ingresar();
void imprimir();

int** matriz;
int	dimen;
void setDimension(int _dimen)
{
	//int** matriz,
	//int	dimen;
	//dimen = _dimen;
}
void segmentar()
{
	//int** matriz;
	//int	dimen;
	matriz = (int**)malloc(dimen * sizeof(int*));
	for (int j = 0; j < dimen; j++)
		*(matriz + j) = (int*)malloc(dimen * sizeof(int));
	for (int i = 0; i < dimen; i++) {
		for (int j = 0; j < dimen; j++) {
			*(*(matriz + i) + j) = 0;
		}
	}
}
void encerar() {
	//int** matriz;
	//int	dimen;
	for (int i = 0; i < dimen; i++) {
		for (int j = 0; j < dimen; j++) {
			*(*(matriz + i) + j) = 0;
		}
	}
	return;
}
void ingresar() {
	//int** matriz;
	//int	dimen;
	srand(time(NULL));
	int dato;
	
	for (int i = 0; i < dimen; i++)
		for (int j = 0; j < dimen; j++) {
			dato = 10 + rand() % (100 - 1);
			cout << "Posicion de [" << i + 1 << "][" << j + 1 << "]: ";
			cout <<"numero "<< dato << endl;
			*(*(matriz + i) + j) = dato;
		}
}
void imprimir()
{
	//int** matriz;
	//int	dimen;
	for (int i = 0; i < dimen; i++) {
		for (int j = 0; j < dimen; j++)
		{
			cout << *(*(matriz + i) + j);
			printf("%*s", j + 5, "");
		}
		printf("\n");
	}
}


int main()
{
	//int** matriz;
	//int	dimen;
	cout << "Ingrese el tamaño de la matriz: " << endl;
	cin >> dimen;
	setDimension(dimen);
	segmentar();
	encerar();
	ingresar();
	imprimir();
	printf("\n\n");
    return 0;
}

