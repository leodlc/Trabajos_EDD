#pragma once
#include <iostream>
using namespace std;
//float x;
template <class T>
class Complejo;
template <typename T>
ostream& operator <<(ostream& o, const Complejo<T>& A);
template <class T>
class Complejo
{
public:
	Complejo(T real = 0, T img = 0);
	//Complejo();

	T getReal();
	void setReal(T real);
	T getImg();
	void setImg(T img);
	void toString();
	Complejo<T>& operator +(const Complejo<T>& A);
	Complejo<T>& operator -(const Complejo<T>& A);
	//Complejo(float real, float imaginario);
	//~Complejo();

protected:
private:
	T real;
	T img;


};
