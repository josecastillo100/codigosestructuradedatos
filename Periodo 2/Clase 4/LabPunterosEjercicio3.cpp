#include <iostream>

using namespace std;

int main()
{
	char c = 'A';
	double *p = &c; 
	
	cout << "*p: " << p << endl;
	
	//Explicando el error: El tipo de datos del puntero p no coincide con el tipo de datos de la variable c
		
	return 0;
}


