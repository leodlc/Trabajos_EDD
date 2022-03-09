#include <iostream>
#include "Complejo.h"
using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Complejo<int> A(1, 3), B(2, 4);
	Complejo<int> C;
	int x, y;
	cout << "suma de complejos" << endl;
	C = A + B;
	cout << C.getReal() << " +  " << C.getImg() << "i" << endl;
	C.setImg(0);
	C.setReal(0);
	cout << "resta de complejos" << endl;
	C = A - B;
	cout << C.getReal() << " -  " << C.getImg() << "i" << endl;
	cin.ignore();
	system("Pause");
	return 0;
}