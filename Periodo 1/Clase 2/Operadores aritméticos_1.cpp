#include <iostream>
using namespace std;

int main(){
	int x = 5;
	int y = 2;
	cout << x + y << endl;		//Suma Suma dos valores x + y
	cout << x - y << endl;		//Resta Resta un valor de otro x - y
	cout << x * y << endl;		//Multplicación Multiplcia dos valores x * y
	
	x = 12;
	y = 3;
	cout << x / y << endl;		//Dviide un valor por otro x / y
	
	x = 5;
	y = 2;
	cout << x % y << endl;		//Devuelve el residuo de la división x% y
	
	++x;						//Aumenta el valor de una variable en 1
	cout << x << endl;
	
	x = 5;
	--x;						//Disminuye el valor de una variable en 1
	cout << x << endl;
	
	return 0;
}
