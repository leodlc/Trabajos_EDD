#pragma once
//template <class T>
class Matriz
{
private:
	int d;
	int** mat;
public:
	Matriz();
	Matriz(int);
	void segmentar();
	void encerar();
	void ingresar();
	void imprimir();
	void setDimension(int);
	void setMatriz(int** matri);
	int getDimension();
	int** getMatriz();
	//void pasarABinario(Matriz matriz)
	int buscarBinario(int);

	//Matriz<T> procesar(Matriz<T>);
};
