#pragma once
#include <iostream>
using namespace std;
template <class T>

class Conjunto;

template <typename T>
ostream& operator <<(ostream& o, const Conjunto<T>& A);
template <class T>
class Conjunto
{
private:
	T elemento[4];
	
public:
	Conjunto(T elemento[4]);
	~Conjunto();
	void setElementos(T elemento[4]);
	int getElementos();
	
	Conjunto<T>& operator ==(const Conjunto<T>& A);
};

