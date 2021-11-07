#include <iostream>
#include <array>
#include <ctime>
#include <windows.h>
#include <string> // Funciones para cadenas

using namespace std;

int main()
{
	array<char, 8> letras = {'J', 'U', 'V', 'E','N', 'T', 'U', 'D'};
	
	cout << "letras[5] = " << letras[5] << endl;
	
	cout <<  "letras[0] = " << letras[0] << ", " << "letras[3] = " << letras[3] << ", " << "<<letras[5] = " << letras[5] << endl; 
	
	cout << "(letras.size() - 1) = " << (letras.size() - 1) << endl;
	
	for (int i = 5; i > 2; i--)
  		cout << letras[i] << " ";
	cout << endl;
	
	cout << "letras[letras.size() / 2] = " << letras[letras.size() / 2];						
		
	return 0;
}

