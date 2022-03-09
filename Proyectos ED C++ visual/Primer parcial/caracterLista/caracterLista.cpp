#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
char* ingreso(const char*);

char* ingreso(const char* msj) {
	char dato[5];
	char c;
	int i = 0;
	printf("%s", msj);
	while ((c = _getch()) != 13) {
		if (c >= '0' && c <= '9') {
			printf_s("%c", c);
			dato[i++] = c;
		}
	}
	dato[i] = '\0';
	return dato;
}

int main(int argc, char** argv) {

	int valor;
	char datos[5];
	strcpy_s(datos, ingreso("Ingrese los datos en entero "));
	valor = atoi(datos);
	printf("\n%d", valor * 5);

	return 0;
}
