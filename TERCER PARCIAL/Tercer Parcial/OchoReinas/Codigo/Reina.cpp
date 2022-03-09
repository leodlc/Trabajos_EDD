
#include "Reina.h"
#include <iostream>
#include <fstream> 


Reina::Reina(int n1)
{
	n=n1;
	validar = new bool *[n];
	tablero= new char *[n];
	for(int i=0;i<n;i++){
		validar[i]=new bool [n];
		tablero[i]=new char[n];
		for(int j=0;j<n;j++){
			*(*(validar+i)+j)=false;
			*(*(tablero+i)+j)='.';
		}
	}
	enter.open("solucion.txt",fstream::out); //para leer in, para salir es out escribir
	enter<<"solucion "<<n<<"*"<<n<<endl<<endl;
	contador=0;
}


Reina::~Reina()
{
   
}

void Reina::solucion(int x, int y, int n1)
{
   *(*(tablero+x)+y)='R';
	bloquear(x,y);
	if(n1==n){
		mostrar();
	}else{
		for(int i=0;i<n;i++){
			if(*(*(validar+i)+y+1)==false){
				solucion(i,y+1,n1+1);
			}
		}
	}
	quitarRelleno(x,y);
}

void Reina::bloquear(int x, int y)
{
   	int aux1,aux2;
	aux2=y;
	aux1=0;
	while(aux1<n){ //vertical
		*(*(validar+aux1)+aux2)=true;
		aux1++;
	}
	aux2=0;
	aux1=x;
	while(aux2<n){
	   	*(*(validar+aux1)+aux2)=true;
		aux2++;
	}
	aux2=y;  //Diagonales
	aux1=x;
	while(aux1>0&&aux2>0){
	  	aux1--;
	  	aux2--;
	}
	aux2=y;
	aux1=x;
	while(aux1<n&&aux2>0){
	   	aux1++;
	   	aux2--;
	}
	aux1--;
	aux2++;
	while(aux1>=0&&aux2<n){
		*(*(validar+aux1)+aux2)=true;
		aux1--;
		aux2++;
	}
}


void Reina::quitarRelleno(int x, int y)
{
   *(*(tablero+x)+y)='.';
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
	   		*(*(validar+i)+j)=false;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(*(*(tablero+i)+j)=='R')
				bloquear(i,j);
		}
	}
}


void Reina::mostrar()
{
   	contador++;
	enter<<"Solucion N "<<contador<<endl;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			enter<<*(*(tablero+i)+j)<<" ";
		}
		enter<<endl;
	}
	enter<<endl;
}

void Reina::solucionReinas()
{
   	for(int i=0;i<n;i++){
		solucion(i,0,1);
	}
	enter.close();
}
