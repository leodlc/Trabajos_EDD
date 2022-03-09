#pragma once
template <class T>
class Matriz
{
private:
	T d;
	T** mat;
public:
	Matriz();
	Matriz(T);
	void segmentar();
	void encerar();
	void ingresar();
	void imprimir();
	void setDimension(T);
	void setMatriz(T** matri);
	T getDimension();
	T** getMatriz();

	Matriz<T> procesar(Matriz<T>);
};
