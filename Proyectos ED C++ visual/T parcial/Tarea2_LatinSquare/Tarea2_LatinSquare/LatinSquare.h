#pragma once
#include <iostream>
//template <class T>
class LatinSquare
{
private:
	int  i, j, k, p = 0, m = 0;
	int dimension;

public:
	LatinSquare();
	int getDimension();
	int getI();
	int getJ();
	int getK();
	int getP();
	int getM();
	void obtainSquare(int dimension);

};

