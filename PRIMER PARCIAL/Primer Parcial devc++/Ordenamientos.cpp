#include<stdio.h>
#include <math.h>
#include <iostream>
#include<conio.h>
#include <string.h>
//#define N 10
using namespace std;

struct Empleado{
	char nombre[20];
	int identificacion;
};

struct Ciudad{
	char nombre[20];
	int numEmpleados;
	Empleado empleados[100];
}ciudades[100];

//DECLARACION DE FUNCIONES Y PROCEDIMIENTOS
void mostrar_menu();
void lectura_datos(int numCiudades);
void mostrar_datos(int numCiudades);
void mostrar_datos_ordenados(int numCiudades);
void burbuja(int numCiudades);
void insercion(int numCiudades);
void seleccion(int numCiudades);
void shell(int numCiudades);
void aux_quicksort(int posicion, int izq, int der);
void quicksort(int numCiudades);

void lectura_datos(int numCiudades){
	for (int i = 0; i< numCiudades; i++){
		cout<<"=============================================="<<endl;
		cout<<"Ingrese el numero de la ciudad ["<<i + 1<<"]:";
		cin>>ciudades[i].nombre;
		cout<<"Ingrese el numero de empleados para "<<ciudades[i].nombre<<":";
		cin>>ciudades[i].numEmpleados;
		cout<<"=============================================="<<endl;
		cout<<"Ingreso de empleados ciudad:"<<ciudades[i].nombre<<endl;
		cout<<"=============================================="<<endl;
		for (int j = 0; j < ciudades[i].numEmpleados; j++){
			cout<<"=========================================="<<endl;
			cout<<"Empleado ["<<j + 1<<"]"<<endl;
			cout<<"=========================================="<<endl;
			cout<<"Ingrese numero:";
			cin>>ciudades[i].empleados[j].identificacion;
			cout<<"Ingrese nombre empleado:";
			cin>>ciudades[i].empleados[j].nombre;
		}
	}
}

void mostrar_datos(int numCiudades){
	for (int i = 0; i < numCiudades; i++){
		cout<<"=============================================="<<endl;
		cout<<"Ciudad es :"<<ciudades[i].nombre<<endl;
		cout<<"=============================================="<<endl;
		for (int j = 0; j < ciudades[i].numEmpleados; j++){
			cout<<"=========================================="<<endl;
			cout<<"Empleado ["<<j + 1<<"]"<<endl;
			cout<<"Numero:"<<ciudades[i].empleados[j].identificacion<<endl;
			cout<<"Nombre:"<<ciudades[i].empleados[j].nombre<<endl;
			cout<<"=========================================="<<endl;
		}
	}
	getch();
}

void mostrar_datos_ordenados(int numCiudades){
	for (int i = 0; i < numCiudades; i++){
		cout<<"========================================"<<endl;
		cout<<"Ciudad es :"<<ciudades[i].nombre<<endl;
		cout<<"========================================"<<endl;
		cout<<"Nombre\tNumero"<<endl;
		for (int j = 0; j < ciudades[i].numEmpleados; j++){
			cout<<ciudades[i].empleados[j].nombre<<"\t"<<ciudades[i].empleados[j].identificacion<<endl;
		}
	}
	getch();
}

void seleccion(int numCiudades){
	char nombreAux[20];
	int identificacionAux;
	for (int c = 0; c < numCiudades; c++){
		int tamanio = ciudades[c].numEmpleados;
		int minimo;
		for(int i = 0; i < tamanio; i++ )
		{
			minimo = i;
			for( int j = i + 1; j < tamanio; j++)
			{
				if (strcmp(ciudades[c].empleados[j].nombre,ciudades[c].empleados[j - 1].nombre) < 0){
					minimo = j;
		        }
	        	strcpy(nombreAux,ciudades[c].empleados[i].nombre);
          		identificacionAux = ciudades[c].empleados[i].identificacion;
				strcpy(ciudades[c].empleados[i].nombre,ciudades[c].empleados[minimo].nombre);
            	ciudades[c].empleados[i].identificacion = ciudades[c].empleados[minimo].identificacion;
				strcpy(ciudades[c].empleados[minimo].nombre,nombreAux);
          		ciudades[c].empleados[minimo].identificacion = identificacionAux;
			}
		}
	}
    cout<<"Datos empleados ordenados alfabeticamente por Metodo de Seleccion"<<endl;
	mostrar_datos_ordenados(numCiudades);
	getch();
}

void quicksort(int numCiudades){
	for (int c = 0; c < numCiudades; c++){
		int aux = ciudades[c].numEmpleados - 1;
		aux_quicksort(c,0, aux);
	}
	cout<<"Datos empleados ordenados alfabeticamente por Metodo de Quicksort"<<endl;
	mostrar_datos_ordenados(numCiudades);
	getch();

}

void aux_quicksort(int posicion, int izq, int der) {
	char pivote[20];
	int pivoteIdent;
	strcpy(pivote,ciudades[posicion].empleados[izq].nombre);
	pivoteIdent = ciudades[posicion].empleados[izq].identificacion;
    int i = izq;
    int j = der;

    char nombreAux[20];
	float identificacionAux;

    while (i < j) {
    	while(strcmp(ciudades[posicion].empleados[i].nombre,pivote) <= 0 && i < j){
            i++;
        }
        while(strcmp(ciudades[posicion].empleados[i].nombre,pivote) > 0){
            j--;
        }
        if (i < j) {
            strcpy(nombreAux,ciudades[posicion].empleados[i].nombre);
            identificacionAux = ciudades[posicion].empleados[i].identificacion;
            strcpy(ciudades[posicion].empleados[i].nombre,ciudades[posicion].empleados[j].nombre);
            ciudades[posicion].empleados[i].identificacion = ciudades[posicion].empleados[j].identificacion;
            strcpy(ciudades[posicion].empleados[j].nombre,nombreAux);
            ciudades[posicion].empleados[j].identificacion = identificacionAux;
        }
    }

    strcpy(ciudades[posicion].empleados[izq].nombre,ciudades[posicion].empleados[j].nombre);
	ciudades[posicion].empleados[izq].identificacion = ciudades[posicion].empleados[j].identificacion;
    strcpy(ciudades[posicion].empleados[j].nombre,pivote);
	ciudades[posicion].empleados[j].identificacion = pivoteIdent;

    if (izq < j - 1) {
        aux_quicksort(posicion, izq, j - 1);
    }
    if (j + 1 < der) {
        aux_quicksort(posicion, j + 1, der);
    }
}

void shell(int numCiudades){
    int salto, aux, i;
    bool cambios;
    char nombreAux[20];
	int identificacionAux;

	for (int c = 0; c < numCiudades; c++){
	    for (salto = ciudades[c].numEmpleados / 2; salto != 0; salto /= 2) {
	        cambios = true;
	        while (cambios) {
	            cambios = false;
	            for (i = salto; i < ciudades[c].numEmpleados; i++)
	            {
	            	if (strcmp(ciudades[c].empleados[i - salto].nombre,ciudades[c].empleados[i].nombre) < 0){
	                		strcpy(nombreAux,ciudades[c].empleados[i].nombre);
          					identificacionAux = ciudades[c].empleados[i].identificacion;
	        				strcpy(ciudades[c].empleados[i].nombre,ciudades[c].empleados[i - salto].nombre);
            				ciudades[c].empleados[i].identificacion = ciudades[c].empleados[i - salto].identificacion;
	                        strcpy(ciudades[c].empleados[i - salto].nombre,nombreAux);
          					ciudades[c].empleados[i - salto].identificacion = identificacionAux;
	                        cambios = true;
	                }
	            }
	        }
	    }
	}
    cout<<"Datos empleados ordenados alfabeticamente por Metodo Shell"<<endl;
	mostrar_datos_ordenados(numCiudades);
	getch();
}


void insercion(int numCiudades) {
	char nombreAux[20];
	int identificacionAux;
	for (int c = 0; c < numCiudades; c++){
	    int n=ciudades[c].numEmpleados;
	    int i,j;
	    for(i=1;i<n;i++){
	      j=i;
	      strcpy(nombreAux,ciudades[c].empleados[i].nombre);
          identificacionAux = ciudades[c].empleados[i].identificacion;
	      while(j>0 && (strcmp(ciudades[c].empleados[j].nombre,ciudades[c].empleados[j - 1].nombre) < 0)){
	        strcpy(ciudades[c].empleados[j].nombre,ciudades[c].empleados[j - 1].nombre);
            ciudades[c].empleados[j].identificacion = ciudades[c].empleados[j - 1].identificacion;
	        j--;
	      }
	      strcpy(ciudades[c].empleados[j].nombre,nombreAux);
          ciudades[c].empleados[j].identificacion = identificacionAux;
	    }
	}
    cout<<"Datos empleados ordenados alfabeticamente por Metodo de Insercion"<<endl;
	mostrar_datos_ordenados(numCiudades);
	getch();
}

void burbuja(int numCiudades){
	char nombreAux[20];
	int identificacionAux;
	for (int c = 0; c < numCiudades; c++){
    	for (int i = 0; i < ciudades[c].numEmpleados; i++){
        	for (int j = 0; j < ciudades[c].numEmpleados - 1; j++){
            	if (strcmp(ciudades[c].empleados[j].nombre,ciudades[c].empleados[j + 1].nombre) > 0){
					strcpy(nombreAux,ciudades[c].empleados[j].nombre);
               		identificacionAux = ciudades[c].empleados[j].identificacion;
               		strcpy(ciudades[c].empleados[j].nombre,ciudades[c].empleados[j + 1].nombre);
               		ciudades[c].empleados[j].identificacion = ciudades[c].empleados[j + 1].identificacion;
               		strcpy(ciudades[c].empleados[j + 1].nombre,nombreAux);
               		ciudades[c].empleados[j + 1].identificacion = identificacionAux;
            	}
        	}
    	}
	}
	cout<<"Datos empleados ordenados alfabeticamente por Metodo de Burbuja"<<endl;
	mostrar_datos_ordenados(numCiudades);
	getch();
}

void mostrar_menu(){
    printf ( "BIENVENIDO PORFAVOR COMPLETE LOS DATOS\n");
    printf ( "====MENU DE OPCIONES====\n");
    printf ( "INGRESE EL 1 INGRESO DE DATOS\n");
    printf ( "INGRESE EL 2 METODO BURBUJA\n");
    printf ( "INGRESE EL 3 METODO INSERCION\n");
    printf ( "INGRESE EL 4 METODO SELECCION\n");
    printf ( "INGRESE EL 5 METODO SHELL\n");
    printf ( "INGRESE EL 6 METODO QUICKSORT\n");
    printf ( "INGRESE EL 7 SALIR\n");
    printf ( "DIGITE La OPCION 1 PARA CONTINUAR: ");
}

int main (){
    int op;

    int numCiudades;
    do {
        system( "cls");
        mostrar_menu();
        scanf ( "%d", &op);
        system( "cls");
    	switch (op){
    		case 1:
    			cout<<"Numero de ciudades a Ingresar:";
				cin>>numCiudades;
    			lectura_datos(numCiudades);
    			break;
    		case 2:
    			burbuja(numCiudades);
    			break;
    		case 3:
    			insercion(numCiudades);
    			break;
    		case 4:
    			seleccion(numCiudades);
    			break;
    		case 5:
    			shell(numCiudades);
    			break;
    		case 6:
    			quicksort(numCiudades);
    			break;
    		case 7:
    		    printf ( "======================\n");
    			printf ( "FIN DEL PROGRAMA\n");
    			printf ( "======================\n");
    			break;
    	}
    } while (op != 7);
	return 0;
}